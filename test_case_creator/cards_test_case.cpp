#include <bits/stdc++.h>

void init() {
    srand(time(0));
}

int random_integer(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

long long int random_ll_integer(long long int lower, long long int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

char suits[] = {'C', 'D', 'H', 'S'};
char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

char **sorted_cards() {
    char **cards;
    cards = new char*[55];
    for (int i = 0; i < 55; i++) {
        cards[i] = new char[5];
    }
    int idx = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[idx][0] = ranks[j];
            cards[idx][1] = suits[i];
            cards[idx][2] = '\0';
            idx++;
        }
    }
    return cards;
}

char **shuffled_cards() {
    char **cards = sorted_cards();
    for (int i = 0; i < 52; i++) {
        int idx1 = random_integer(0, 51);
        int idx2 = idx1;
        while (idx2 == idx1) idx2 = random_integer(0, 51);
        char temp = cards[idx1][0];
        cards[idx1][0] = cards[idx2][0];
        cards[idx2][0] = temp;
        temp = cards[idx1][1];
        cards[idx1][1] = cards[idx2][1];
        cards[idx2][1] = temp;
    }
    return cards;
}

int main() {
    init();
    int TC = 10;
    while(TC--) {
        char **cards = shuffled_cards();
        for (int i = 0; i < 25; i++) {
            printf("%s ", cards[i]);
        }
        printf("%s\n", cards[25]);
        for (int i = 26; i < 51; i++) {
            printf("%s ", cards[i]);
        }
        printf("%s\n", cards[51]);
    }
    printf("#\n");
    return 0;
}