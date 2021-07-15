#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int inf = 1000000009;

char ALPHABET[21] = "ABCDEFGHIJKLMNOPQRST";
char MAP[99][58];
char ROW_TITLE[59];

long double score[99][58];

long double adjusted_dist(int i1, int j1, int i2, int j2) {
  long double dist = abs(i1 - i2) + abs(j1 - j2) / 2.0;

  if (dist)
    return 100 - pow(100, 1 / dist);
  else
    return 0;
}

void calculate_the_score_table(int row, int column) {
  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++)
      score[i][j] = 0.0;

  for (int k = 0; k < row; k++) {
    for (int m = 0; m < column; m++) {
      if (MAP[k][m] != '-')
        continue;
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
          if (MAP[i][j] == 'X')
            score[k][m] += adjusted_dist(k, m, i, j);
        }
      }
    }
  }
}

int is_better_seat(long double row_score1,
                   int aisle_num1,
                   long double row_score2,
                   int aisle_num2) {
  if (row_score1 < row_score2) {
    return 1;
  } else if (row_score1 > row_score2) {
    return 0;
  }

  if (aisle_num1 > aisle_num2) {
    return 1;
  } else {
    return 0;
  }
}

void make_reservation(int n, int row, int column, int* res_i, int* res_j) {
  calculate_the_score_table(row, column);

  long double seat_block_score = -inf;
  int aisle_count = 0;
  int current_index[2] = {inf, inf};

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      if (MAP[i][j] != '-')
        continue;
      long double seat_block_score_temp = 0;
      int aisle_count_temp = 0;
      int empty_seat_count = 0;
      int l = j;
      while (l < column && empty_seat_count < n && MAP[i][l] != 'X') {
        if (MAP[i][l] == '-') {
          seat_block_score_temp += score[i][l];
          empty_seat_count++;
        } else if (MAP[i][l] == '|') {
          aisle_count_temp++;
        }
        l++;
      }

      if (empty_seat_count == n &&
          is_better_seat(seat_block_score, aisle_count, seat_block_score_temp,
                         aisle_count_temp)) {
        seat_block_score = seat_block_score_temp;
        aisle_count = aisle_count_temp;
        current_index[0] = i;
        current_index[1] = j;
      }
    }
  }

  *res_i = current_index[0];
  *res_j = current_index[1];

  if (*res_i == inf)  // i don't need to control res_j
    return;

  for (int l = *res_j; l < n + aisle_count + *res_j; l++)
    if (MAP[*res_i][l] != '|')
      MAP[*res_i][l] = '+';
  return;
}

void print_board(int row, int column) {
  printf("  ");
  for (int i = 0; i < column; i++) {
    if (ROW_TITLE[i] == '|')
      printf("  |  |");
    else
      printf("%3c", ROW_TITLE[i]);
  }
  printf(" \n");

  for (int i = 0; i < row; i++) {
    printf("%-2d", i + 1);
    for (int j = 0; j < column; j++) {
      if (MAP[i][j] == '|')
        printf("  |  |");
      else
        printf("%3c", MAP[i][j]);
    }
    printf(" \n");
  }
}

void create_map() {
  for (int i = 0; i < 99; i++)
    for (int j = 0; j < 58; j++)
      MAP[i][j] = '-';
}

void convert_from_plus_to_x(int x, int y, int n) {
  int processed_seat_count = 0;
  int j = y;
  while (processed_seat_count < n) {
    if (MAP[x][j] == '+') {
      MAP[x][j] = 'X';
      processed_seat_count++;
    }
    j++;
  }
}

void show_the_reserved_seats(int x, int y, int n) {
  printf("Reserved seats:");
  int processed_seat_count = 0;
  int j = y;
  while (processed_seat_count < n) {
    if (MAP[x][j] == '+') {
      processed_seat_count++;
      printf(" %d%c", x + 1, ROW_TITLE[j]);
    }
    j++;
  }
  printf("\n");
}

int main() {
  create_map();

  int row, column, seats_per_row, number_of_aisles;

  printf("Number of rows: ");
  scanf("%d", &row);

  printf("Number of seats per row: ");
  scanf("%d", &seats_per_row);

  printf("Number of aisles: ");
  scanf("%d", &number_of_aisles);

  // add aisles
  column = seats_per_row + number_of_aisles;

  for (int i = 0; i < number_of_aisles; i++) {
    int location_of_aisle;

    printf("Add aisle %d after seat: ", i + 1);
    scanf("%d", &location_of_aisle);

    for (int j = 0; j < row; j++)
      MAP[j][location_of_aisle + i] = '|';
  }

  // create the row label (for instance: A B | | C D)
  int index_of_letter = 0;
  for (int i = 0; i < column; i++) {
    if (MAP[0][i] != '|') {
      ROW_TITLE[i] = ALPHABET[index_of_letter];
      index_of_letter++;
    } else {
      ROW_TITLE[i] = '|';
    }
  }

  // start to reservation
  int n = 0;
  while (n != -1) {
    if (n == 0) {
      print_board(row, column);
    } else if (n > 0) {
      int res_i = -1, res_j = -1;
      make_reservation(n, row, column, &res_i, &res_j);

      if (res_i == inf) {
        printf("No available seats for the requested reservation!\n");
      } else {
        show_the_reserved_seats(res_i, res_j, n);
        print_board(row, column);
        convert_from_plus_to_x(res_i, res_j, n);
      }
    }
    printf("The number of people in the reservation\n");
    printf(" (0: print current reservations, -1: exit): ");
    scanf("%d", &n);
  }

  return 0;
}
