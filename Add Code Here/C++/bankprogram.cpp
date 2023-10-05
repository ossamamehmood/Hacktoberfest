#include <iostream>
#include <conio.h>
#define max 10
using namespace std;

struct antri
{
    int data;
};

struct identitas
{
    char nama[20];
    char transaksi[15];
    int nominal;
};

int main()
{

    identitas id[15];
    antri ant[15];
    int cek=0, y=0, hapus;
    char pil;
    do {
        cout<<"\n========================";
        cout<<"\nMENU ANTRIAN BANK COTAN ";
        cout<<"\n========================"<<endl<<endl;
        cout<<"1. Pelanggan datang"<<endl;
        cout<<"2. Pelanggan dilayani"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<endl;
            cout<<"Masukkan pilihan Anda (1-3)\t= ";
            cin>>pil;
         cout<<endl;
if(pil!='1' && pil !='2' && pil !='3' )
{
    cout<<"Anda salah memasukkan pilihan\n\n";
    system("PAUSE");
}
            else
            {
                if(pil=='1')   
                {
                    if(cek==15 && y==15)
                    {
                        cout<<"ANTRIAN PENUH!!!";
                    }
                        cout<<endl;
                        cout<<"Nama Pelanggan\t: ";
                        cin>>id[cek].nama;
                        cout<<"Jumlah transaksi: ";
                        cin>>id[cek].transaksi;
                        cout<<endl;
                        cek++;
                        
                        cout<<"Antrian saat ini\t:\n\n";
                                for(int z=0;z<cek;z++)
                                {
                                cout<<"Nomor Antri\t: "<<z+1;
                                cout<<endl;
                                cout<<"Nama pelanggan\t: "<<id[z].nama<<endl;
                                cout<<"Jumlah transaksi: "<<id[z].transaksi<<endl;
                                }
                    cout<<"\n\n";
                    system("PAUSE");
                }
                else
                {
                    if(pil=='2')     
                    {
                        if(cek==0)
                            cout<<"Antrian kosong";
                        else
                        {
                            for(int z=0;z<cek;z++)
                            hapus=z;
                            for(int v=0;v<cek;v++)
                                ant[v].data=ant[v+1].data;
                            	ant[cek].data=NULL;
                            cek--;
                            cout<<"\nAntrian dengan nomor 1 diproses\n";
                            cout<<"\n\t\tData Nasabah \n\n";
                            cout<<"Nama pelanggan\t: "<<id[0].nama<<endl;
                            cout<<"Jumlah transaksi: "<<id[0].transaksi<<endl;
                            {
                                int b;
                                for(b=0;b<cek;b++)
                                id[b]=id[b+1];
                                b--;
                            }
                        }
                        cout<<endl;
                        if(cek==0)
                            cout<<"Antrian kosong";
                        else
                            cout<<"Nomor Antrian saat ini : ";
                                for(int z=0;z<cek;z++)
                                {
                                    cout<<" | ";
                                    cout<<" "<<z+1;
                                    cout<<" | ";
                                }
                    cout<<endl<<endl;
                    system("PAUSE");
                    }

                }
            }

    }while(pil!='3');
}
