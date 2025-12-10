#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    Card *c = (Card *)malloc(sizeof(Card));
    if (!c){
        fprintf(stderr, "No memory\n");
        exit(-1);
    }
    c->prev = NULL;
    /* (*c).prev = NULL; */
    c->next = NULL;
    strcpy(c->suit, suit);
    strcpy(c->value, value);
    
    return c;
}

void push_front(Deck *deck, Card *card){
    if (deck->head == NULL){
        deck->head = card;
        deck->tail = card;
    }else{
        deck->head->prev = card;
        card->next = deck->head;
        deck->head = card;
    }
}
Deck *create_deck(void){
    Deck *deck = (Deck *)malloc(sizeof(Deck));
    if (!deck){
        fprintf(stderr, "No memory\n");
        exit(-1);
    }
    deck->head = NULL;
    deck->tail = NULL;
    const char *suits[] = {"pikk", "kor", "karo", "treff"};
    const char *values[] = {"A", "2", "3", "4", "5",
        "6", "7", "8", "9", "10", "J", "Q", "K"};
    for (unsigned int i = 0; i < sizeof(suits) / sizeof(suits[0]); i++){
        for (unsigned int j = 0; j < sizeof(values)/sizeof(values[0]); j++){
            push_front(deck, create_card(suits[i], values[j]));
        }
    }
    return deck;
}

void print_deck_forward(Deck *deck){
    Card *card = deck->head;
    while (card != NULL){
        printf("%6s %3s\n", card->suit, card->value);
        card = card->next;
    }
}
void print_deck_backword(Deck *deck){
    for (Card *card = deck->tail; card != NULL; card = card->prev){
        printf("%6s %3s\n", card->suit, card->value);
    }
}

Card *pop_front_index(Deck *deck, int index){
    Card *card = deck->tail;
    while (card != NULL){
        if (index == 0){
            break;
        }
        index -= 1;
        card = card->prev;
    }
    if (index != 0 || card == NULL){
        fprintf(stderr, "Tulindexeles\n");
        return NULL;
    }
    if (card->prev){
        card->prev->next = card->next; 
    }else{
        deck->head = card->next;
    }
    if (card->next){
        card->next->prev = card->prev;
    }else{
        deck->tail = card->prev;
    }

    card->prev = NULL;
    card->next = NULL;
    return card;
}

int main(void){
    Deck *deck = create_deck();
    print_deck_forward(deck);
    Deck deck2 = {NULL, NULL};

    for (int i = 0; i < 10; i++){
        Card *card = pop_front_index(deck, rand() % 40);
        printf("Popped card: %s %s\n", card->suit, card->value);
        push_front(&deck2, card);
    }
    printf("deck2\n");
    print_deck_forward(&deck2);

    
    
    return 0;
}



