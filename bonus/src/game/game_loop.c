/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Loop of the navy game
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include "navy.h"
#include "game.h"
#include "my.h"

static game_status_t player_turn(grid_t enemy_grid, socket_t enemy_socket);
static game_status_t enemy_turn(grid_t player_grid, socket_t enemy_socket);

game_status_t navy_loop(game_t *game)
{
    if (game->player_id == FIRST) {
        game->status = player_turn(game->enemy_grid, game->network->client_socket);
        if (game->status != ONGOING)
            return (game->status);
        game->status = enemy_turn(game->player_grid, game->network->client_socket);
        if (game->status != ONGOING)
            return (game->status);
    } else {
        game->status = enemy_turn(game->player_grid, game->network->client_socket);
        if (game->status != ONGOING)
            return (game->status);
        game->status = player_turn(game->enemy_grid, game->network->client_socket);
        if (game->status != ONGOING)
            return (game->status);
    }
    print_grids(game->player_grid, game->enemy_grid);
    return (ONGOING);
}

static game_status_t player_turn(grid_t enemy_grid, socket_t enemy_socket)
{
    char *coord = NULL;
    int row = 0;
    int col = 0;
    ssize_t recv_size = 0;
    char buffer[50] = "";

    coord = get_input();
    if (coord == NULL)
        return (ERROR);
    col = coord[0] - 'A';
    row = coord[1] - '0' - 1;
    if (send(enemy_socket, coord, strlen(coord), 0) == -1) {
        perror("send");
        return (NETWORK_ERROR);
    }
    recv_size = recv(enemy_socket, buffer, strlen("missed"), 0);
    if (recv_size == -1) {
        perror("recv");
        return (NETWORK_ERROR);
    }
    printf("%s: %s\n\n", coord, buffer);
    free(coord);
    enemy_grid[row][col] = (strcmp(buffer, "hit") == 0
                            || enemy_grid[row][col] == HIT) ? HIT : MISS;
    recv_size = recv(enemy_socket, buffer, strlen("not finished"), 0);
    if (recv_size == -1) {
        perror("recv");
        return (NETWORK_ERROR);
    }
    return ((strcmp(buffer, "finished") == 0) ? WON : ONGOING);
}

static game_status_t enemy_turn(grid_t player_grid, socket_t enemy_socket)
{
    int row = 0;
    int col = 0;
    bool is_hit = false;
    bool is_finished = false;
    ssize_t recv_size = 0;
    char buffer[50] = "";

    printf("waiting for enemy's attack...\n");
    recv_size = recv(enemy_socket, buffer, 2, 0);
    if (recv_size == -1) {
        perror("recv");
        return (NETWORK_ERROR);
    }
    buffer[recv_size] = '\0';
    if (buffer == NULL || buffer[0] == 0)
        return (NETWORK_ERROR);
    col = buffer[0] - 'A';
    row = buffer[1] - '1';
    is_hit = cell_is_boat(player_grid[row][col]);
    printf("%s: ", buffer);
    strcpy(buffer, (is_hit) ? "hit" : "missed");
    printf("%s\n\n", buffer);
    if (send(enemy_socket, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return (NETWORK_ERROR);
    }
    player_grid[row][col] = (is_hit || player_grid[row][col] == HIT)?HIT : MISS;
    is_finished = !grid_has_boats(player_grid);
    strcpy(buffer, (is_finished) ? "finished" : "not finished");
    if (send(enemy_socket, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return (NETWORK_ERROR);
    }
    return ((is_finished) ? LOST : ONGOING);
}