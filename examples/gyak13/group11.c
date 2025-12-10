#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Card{
    char suit[10];
    char value[3];
    struct Card *prev;
    struct Card *next;
};
typedef struct Card Card;
struct Deck{
    Card *head;
    Card *tail;
};
typedef struct Deck Deck;

Card *create_card(const char *suit, const char *value){
    Card *card = (Card *)malloc(sizeof(Card));
    if (!card){exit(-1);}
    card->prev = NULL;
    card->next = NULL;
    strcpy(card->suit, suit);
    strcpy(card->value, value);
    return card;
}
void push_front(Deck *deck, Card *card){
    if (deck->head == NULL){
        deck->head = card;
        deck->tail = card;
    }else{
        card->next = deck->head;
        deck->head->prev = card;
        deck->head = card;
    }
}
Deck *init_deck(void){
    Deck *deck = (Deck *)malloc(sizeof(Deck));
    if (!deck){exit(-2);}
    deck->head = NULL;
    deck->tail = NULL;
    const char *suits[] = {"treff", "pikk", "karo", "kor"};
    const char *values[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const int suits_length = sizeof(suits) / sizeof(suits[0]);
    const int values_length = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < suits_length; i++){
        for (int j = 0; j < values_length; j++){
            push_front(deck, create_card(suits[i], values[j]));
        }
    }
    return deck;
}
void print_deck_forward(Deck *deck){
    Card *card = deck->head;
    while (card != NULL){
        printf("%6s - %3s\n", card->suit, card->value);
        card = card->next;    
    }
}
void print_deck_backward(Deck *deck){
    for (Card *card = deck->tail; card != NULL; card = card->prev){
        printf("%6s - %3s\n", card->suit, card->value);
    }
}
Card *pop_front_index(Deck *deck, int index){
    Card *card = deck->head;
    while (card != NULL && index > 0){
        index -= 1;
        card = card->next;
    }
    if (index > 0 || card == NULL){
        printf("Index is too high\n");
        return NULL;
    }else{
        if (card->next){
            card->next->prev = card->prev;
        }else{
            deck->tail = card->prev;
            card->prev->next = NULL;
        }
        if (card->prev){
            card->prev->next = card->next;
        }else{
            deck->head = card->next;
            card->next->prev = NULL;
        }
        card->prev = NULL;
        card->next = NULL;

        return card;
    }
}
int main(void){
    Deck *deck = init_deck();
    Deck d2 = {NULL, NULL};
    for (int i = 0; i < 10; i++){
        Card *c1 = pop_front_index(deck, rand() % 40);
        push_front(&d2, c1);
    }
    printf("deck:\n");
    print_deck_forward(deck);
    printf("d2:\n");
    print_deck_forward(&d2);
    return 0;
}