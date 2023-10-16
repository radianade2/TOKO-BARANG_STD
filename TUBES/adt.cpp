#include "adt.h"

void createListToko(listToko &LT){
    first(LT) = nil;
    last(LT) = nil;
}

void createListProduk(listProduk &LP){
    first(LP) = nil;
}

void addToko(listToko &LT, infotypeToko x){
    adrToko p = new elmToko;
    info(p) = x;
    prev(p) = nil;
    next(p) = nil;
    edge(p) = nil;

    if(first(LT) == nil){
        first(LT) = p; last(LT) = p;
    } else{
        next(p) = first(LT);
        prev(first(LT)) = p;
        first(LT) = p;
    }
}

void addProduk(listProduk &LP, infotypeProduk x){
    adrProduk p = new elmProduk;
    info(p) = x;
    next(p) = nil;

    next(p) = first(LP);
    first(LP) = p;
}

adrToko findToko(listToko LT, string x){
    if(first(LT) == nil){
        return nil;
    } else {
        adrToko p = first(LT);
        while (p != nil && info(p).namaToko != x) {
            p = next(p);
        }
        return p;
    }
}

adrProduk findProduk(listProduk LP, string x){
    if(first(LP) == nil){
        return nil;
    } else {
        adrProduk p = first(LP);
        while(p != nil && info(p).namaProduk !=  x){
            p = next(p);
        }
        return p;
    }
}

adrRelasi findRelasi(listToko LT, listProduk LP, string produk, string toko){
    adrToko p = findToko(LT, toko);
    adrProduk q = findProduk(LP, produk);
    adrRelasi e = edge(p);
    if(e == nil){
        return nil;
    } else {
        while(e != nil && info(e) != q){
            e = next(e);
        }
        return e;
    }
}

void addRelasi(listToko &LT, listProduk LP, string namatoko, string namaproduk) {
    adrToko x = findToko(LT, namatoko);
    adrProduk y = findProduk(LP, namaproduk);
    if(x != nil && y != nil ){
        if(edge(x) == nil){
            adrRelasi z = new elmRelasi;
            info(z) = y;
            next(z) = nil;
            edge(x) = z;
        } else {
            adrRelasi z = new elmRelasi;
            info(z) = y;
            next(z) = nil;
            adrRelasi zz = edge(x);
            while(next(zz) != nil){
                zz = next(zz);
            }
            next(zz) = z;
        }
    }
}

void showToko(listToko LT){
    adrToko p = first(LT);
    while(p != nil){
        cout << info(p).namaToko << " " << info(p).namaMarketplace << endl;
        p = next(p);
    }
    cout << endl;
}

void showProduk(listProduk LP){
    adrProduk p = first(LP);
    while(p != nil){
        cout << info(p).namaProduk << " " << info(p).jenis << endl;
        p = next(p);
    }
    cout << endl;
}

void showAll(listToko LT){
    adrToko p = first(LT);
    while(p != nil){
        cout << info(p).namaToko << " = ";
        adrRelasi q = edge(p);
        while(q != nil){
            cout << info(info(q)).namaProduk << ", ";
            q = next(q);
        }
        cout << endl;
        p = next(p);
    }
    cout << endl;
}

void deleteToko(listToko &LT, adrToko &p, string toko){
    p = findToko(LT, toko);
    if(p == nil) {
        cout<<"Toko tidak ditemukan"<<endl;
    } else {
        if(first(LT) == p && last(LT) == p){
            first(LT) = nil; last(LT) = nil;
        } else if(first(LT) == p) {
            first(LT) = next(first(LT));
            prev(first(LT)) = nil;
            next(p) = nil;
        } else if(last(LT) == p) {
            last(LT) = prev(last(LT));
            next(last(LT)) = nil;
            prev(p) = nil;
        } else {
            next(prev(p)) = next(p);
            prev(next(p)) = prev(p);
            next(p) = nil;
            prev(p) = nil;
        }
    }
}

void deleteProduk(listProduk &LP, adrProduk &p, string x){
    p = findProduk(LP, x);
    if(p == nil) {
        cout<<"Produk tidak ditemukan"<<endl;
    } else {
        if(first(LP) == p && next(first(LP)) == nil){
            first(LP) = nil;
        } else if(first(LP) == p) {
            first(LP) = next(first(LP));
            next(p) = nil;
        } else {
            adrProduk q = first(LP);
            while(next(q) != p){
                q = next(q);
            }
            next(q) = next(p);
            next(p) = nil;
        }
    }
}

void deleteRelasi(listToko &LT, listProduk LP, string produk, string toko){
    adrToko tk = findToko(LT, toko);
    adrRelasi p = findRelasi(LT, LP, produk, toko);
    if(p == nil){
        cout << "Produk tidak ditemukan" << endl;
    } else {
        if(edge(tk) == p && next(edge(tk)) == nil){
            edge(tk) = nil;
        } else if(edge(tk) == p){
            edge(tk) = next(edge(tk));
            next(p) = nil;
        } else {
            adrRelasi e = edge(tk);
            while(next(e) != p){
                e = next(e);
            }
            next(e) = next(p);
            next(p) = nil;
        }
    }
}

int countProduk(listToko LT, string toko){
    adrToko p = findToko(LT, toko);
    adrRelasi q = edge(p);
    int counter = 0;
    while(q!=nil) {
        counter++;
        q = next(q);
    }
    return counter;
}

void showEkstrim(listToko LT, adrToko &Max, adrToko &Min){
    adrToko p = next(first(LT));
    Max = first(LT);
    Min = first(LT);
    while(p!=nil){
        int x = countProduk(LT,info(p).namaToko);
        if (countProduk(LT, info(Max).namaToko)<x) {
            Max = p;
        }
        if (countProduk(LT, info(Min).namaToko)>x) {
            Min = p;
        }
        p = next(p);
    }
}

int menu(){
    cout << "========== MENU ==========" << endl;
    cout << "1. Menambah Data Toko Baru" << endl;
    cout << "2. Menambah Data Barang Baru" << endl;
    cout << "3. Menambah Data Barang pada Toko Tertentu" << endl;
    cout << "4. Mencari Toko" << endl;
    cout << "5. Mencari Barang pada Toko Tertentu" << endl;
    cout << "6. Menghapus Toko" << endl;
    cout << "7. Menghapus Data Barang pada Toko Tertentu" << endl;
    cout << "8. Menampilkan Total Produk pada Toko Tertentu" << endl;
    cout << "9. Menampilkan Toko dengan Barang terlengkap dan terjarang" << endl;
    cout << "10. Menampilkan Seluruh Data" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan menu : ";
    int input; cin >> input;
    cout<<endl;
    return input;
}
