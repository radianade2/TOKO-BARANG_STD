#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define first(L) ((L).first)
#define last(L) ((L).last)
#define info(P) P->info
#define next(P) P->next
#define edge(P) P->edge
#define prev(P) P->prev

struct toko{
    string namaToko, namaMarketplace;
};

struct produk{
    string namaProduk, jenis;
};

typedef toko infotypeToko;
typedef produk infotypeProduk;

typedef struct elmProduk *adrProduk;
struct elmProduk{
    infotypeProduk info;
    adrProduk next;
};

typedef struct elmRelasi *adrRelasi;
struct elmRelasi{
    adrProduk info;
    adrRelasi next;
};

typedef struct elmToko *adrToko;
struct elmToko{
    infotypeToko info;
    adrToko next, prev;
    adrRelasi edge;
};

struct listToko{
    adrToko first, last;
};

struct listProduk{
    adrProduk first;
};

void createListToko(listToko &LT);
void createListProduk(listProduk &LP);
void addToko(listToko &LT, infotypeToko x);
void addProduk(listProduk &LP, infotypeProduk x);
adrToko findToko(listToko LT, string x);
adrProduk findProduk(listProduk LP, string x);
void addRelasi(listToko &LT, listProduk LP, string namatoko, string namaproduk);
adrRelasi findRelasi(listToko LT, listProduk LP, string produk, string toko);
void deleteToko(listToko &LT, adrToko &p, string x);
void deleteProduk(listProduk &LP, adrProduk &p, string x);
void deleteRelasi(listToko &LT, listProduk LP, string produk, string toko);
void showToko(listToko LT);
void showProduk(listProduk LP);
void showAll(listToko LT);
int countProduk(listToko LT, string toko);
void showEkstrim(listToko LT, adrToko &Max, adrToko &Min);
int menu();

#endif // ADT_H_INCLUDED
