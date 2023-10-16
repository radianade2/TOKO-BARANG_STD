#include "adt.h"

int main()
{
    listToko LT;
    listProduk LP;
    createListToko(LT);
    createListProduk(LP);
    string cariToko, Toko, Barang, jawab;
    infotypeToko x;
    infotypeProduk y;
    int pilihan, jmlToko, i, jmlBarang, total;
    adrToko p, Max, Min;
    adrRelasi q;

    pilihan = menu();
    while (pilihan != 0) {
        switch(pilihan) {
        case 1:
            cout << "Ingin menambahkan berapa toko? "; cin >> jmlToko;
            for(i=1; i<=jmlToko; i++){
                cout<<"Masukkan nama toko: ";
                cin>>x.namaToko;
                cout<<"Masukkan nama marketplace toko: ";
                cin>>x.namaMarketplace;
                addToko(LT, x);
                cout<<endl;
            }
            break;
        case 2:
            cout << "Ingin menambahkan berapa barang? "; cin >> jmlBarang;
            for(i=1; i<=jmlBarang; i++){
                cout<<"Masukkan nama barang: ";
                cin>>y.namaProduk;
                cout<<"Masukkan jenis barang: ";
                cin>>y.jenis;
                addProduk(LP, y);
                cout<<endl;
            }
            break;
        case 3:
            cout<<"Ingin menambahkan barang pada toko apa? ";
            cin>>Toko;
            cout<<"Masukkan nama barang: ";
            cin>>Barang;
            addRelasi(LT, LP, Toko, Barang);
            cout<<endl;
            break;
        case 4:
            cout<<"Masukkan toko yang ingin dicari: "; cin>>cariToko;
            p = findToko(LT, cariToko);
            if (p == nil) {
                cout<<"Toko tidak ditemukan"<<endl;
            } else {
                cout<<"Toko ditemukan, berikut datanya:"<<endl;
                cout<<"Nama toko: "<<info(p).namaToko<<endl;
                cout<<"Nama marketplace: "<<info(p).namaMarketplace<<endl;
            }
            cout<<endl;
            break;
        case 5:
            cout<<"Ingin mencari barang di toko apa? ";
            cin>>cariToko;
            cout<<"Masukkan barang yang ingin ditemukan di toko"<<cariToko<<": ";
            cin>>Barang;
            q = findRelasi(LT, LP, Barang, cariToko);
            if (q == nil) {
                cout<<"Barang tidak ditemukan dalam Toko"<<cariToko<<endl;
            } else {
                cout<<"Barang ditemukan"<<endl;
            }
            cout<<endl;
            break;
        case 6:
            cout<<"Ingin menghapus data Toko apa? ";
            cin>>Toko;
            deleteToko(LT,p,Toko);
            cout<<"Berikut data toko yang dihapus:"<<endl;
            cout<<"Nama toko: "<<info(p).namaToko<<endl;
            cout<<"Marketplace: "<<info(p).namaMarketplace<<endl;
            cout<<endl;
            cout<<"Berikut kumpulan data setelah Toko dihapus: "<<endl;
            showAll(LT);
            cout<<endl;
            break;
        case 7:
            cout<<"Ingin menghapus barang di toko apa? ";
            cin>>cariToko;
            cout<<"Masukkan barang yang ingin dihapus di toko"<<cariToko<<": ";
            cin>>Barang;
            deleteRelasi(LT,LP,Barang,cariToko);
            cout<<"Berikut kumpulan data setelah Barang dihapus: "<<endl;
            showAll(LT);
            cout<<endl;
            break;
        case 8:
            cout<<"Ingin menghitung total produk toko apa? ";
            cin>>Toko;
            total = countProduk(LT, Toko);
            cout<<"Total produk pada toko "<<Toko<<" adalah sebanyak: "<<total;
            cout<<endl;
            break;
        case 9:
            showEkstrim(LT,Max,Min);
            cout<<"Ini toko yang memiliki barang terlengkap: "<<info(Max).namaToko;
            cout<<"Ini toko yang memiliki barang terjarang: "<<info(Max).namaToko;
            cout<<endl;
            break;
        case 10:
            cout<<"===BERIKUT DATA KESELURUHAN BARANG PADA SISTEM==="<<endl;
            showAll(LT);
            break;
        cout<<endl;
        }
        cout<<"Kembali ke menu utama? (N/Y):";
        cin>>jawab;
        if (jawab=="Y") {
            cout<<endl<<endl<<endl;
            pilihan = menu();
        } else if (jawab=="N") {
            pilihan = 0;
        }
    }
    cout<<endl;
    cout<<"BYE-BYE"<<endl;
    return 0;
}
