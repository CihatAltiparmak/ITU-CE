#include <stdio.h>
#include <stdlib.h>

typedef struct candidate {
    char letter;
    int votes;
    float percent;
} candidate;

candidate A = { 'A', 0, 0.0 };
candidate B = { 'B', 0, 0.0 };
candidate C = { 'C', 0, 0.0 };
candidate D = { 'D', 0, 0.0 };

candidate max(candidate x, candidate y)
{
    if (x.percent >= y.percent)
        return x;
    else
        return y;
}

candidate min(candidate x, candidate y)
{
    // min func is set not to return first_candidate as well :D
    candidate result = { 'X', -1, -1.0 };
    if (x.letter == y.letter)
        return result;
    
    if (x.percent <= y.percent) // if x equals y, y is always first_candidate, if you look 79th line, you see.
        return x;
    else
        return y;
}

void read_the_data_from_file(char* file_name)
{
    FILE* f = fopen(file_name, "r");

    if (f == NULL)
        return;

    while (!feof(f)) {
        int a = -1, b = -1, c = -1, d = 1;
        fscanf(f, "%d %d %d %d", &a, &b, &c, &d);
        if (a == -1)
            break;

        A.votes += a;
        B.votes += b;
        C.votes += c;
        D.votes += d;
    }

    fclose(f);
}

void calculate_percents_of_candidates()
{
    double total_vote = A.votes + B.votes + C.votes + D.votes;

    A.percent = (A.votes / total_vote) * 100;
    B.percent = (B.votes / total_vote) * 100;
    C.percent = (C.votes / total_vote) * 100;
    D.percent = (D.votes / total_vote) * 100;    
}

void evaluate_states_of_candidates()
{
    /* 
    * hack :)
    * trick: min (first_candidate, first_candidate) = {X, -1, -1.0}, shortly, it's -inf of candidates.
    * hence, by using these two tricks and by eliminating leader candidate(first_candidate), we can find second leader candidate.
    */
    candidate first_candidate = max(max(A, B), max(C, D));
    candidate second_candidate = max(
        max(
            min(A, first_candidate),
            min(B, first_candidate)),
        max(
            min(C, first_candidate),
            min(D, first_candidate)));

    if (first_candidate.percent > 50)
        printf("Winner: %c", first_candidate.letter);
    else
        printf("Second round: %c and %c", first_candidate.letter, second_candidate.letter);
}

int main(int argc, char* argv[])
{
    char* file_name = argv[1];
    read_the_data_from_file(file_name);
    calculate_percents_of_candidates();
    evaluate_states_of_candidates();
    return 0;
}
