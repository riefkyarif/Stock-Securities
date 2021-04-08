#include <stdlib.h>
#include <stdio.h>
#include <string.h>
     
void portofolio();
void menuportofolio();
void cetakporto();
void belisaham();
void insert_end();
void jualsaham();
void delete_pos();
int jual, num, i; 
void searching();

// for account data
char idakun[10];
char password[12];
int cash = 0;
void displaycash();
void fordelay(int j);
void tambahkurangdana();
void help();

// struct buying and selling shares
struct node{
	
    int info;
    char emiten[10];
    int lot;
    struct node *next;
};

struct node *start=NULL;

// security patch struct
struct pembaruan{
	
	char patch[20];	
	struct pembaruan *next;
};

typedef struct pembaruan Pembaruan;
typedef Pembaruan *PembaruanPtr;

// for sorting		
void sortnama();
void swap(struct node *a, struct node *b);

// for security patches
void updatepatch();
void enQueue1(PembaruanPtr *headPtr1, PembaruanPtr *tailPtr1, char nama[20]);
void deQueue1(PembaruanPtr *headPtr1, PembaruanPtr *tailPtr1);
int isEmpty1(PembaruanPtr headPtr1);
void printQueue1(PembaruanPtr currentPtr);
PembaruanPtr headPtr1 = NULL;
PembaruanPtr tailPtr1 = NULL;

// Main menu function of Sayur Asem Sekuritas
int main(){
    int choice;
    while(1){               
		system("cls");
		printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
		printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
		printf("===================================================  Selamat Datang  ===================================================\n\n");
		printf("=====================================================  Menu Utama  =====================================================\n\n");
                
		displaycash();
		printf("\n\n\n [tekan 0] Bantuan");
		printf("\n [tekan 1] Pengaturan Pengguna (Log in)");
        printf("\n [tekan 2] Portofolio");               
        printf("\n [tekan 3] Beli Saham");
        printf("\n [tekan 4] Jual Saham");
		printf("\n [tekan 5] Cari Emiten");       
        printf("\n [tekan 6] Top up/Tarik dana Cash");
        printf("\n [tekan 7] Update Patch keamanan");
        printf("\n\n [tekan 8] Keluar Program");
        printf("\n\n--------------------------------------\n");
        printf("  Pilihan:\t");
    	scanf("%d",&choice);
        switch(choice){
        	case 0:
        		help();
        		break;
			case 1:
				dataawal();
				break;
            case 2:
            	menuportofolio();
				break;            	
            case 3:
 				if(!strcmp(idakun,"sayurasem") && !strcmp(password,"12345")){
				  
                	belisaham();
                	break;				
    			}   			
				else{
					
  					printf("\n\n  #  Silakan Login untuk menggunakan fitur ini.\n\n");
	                printf("\n > [Enter] untuk kembali.");
	                getch();
	                break;
 				}

			case 4:
 				if(!strcmp(idakun,"sayurasem") && !strcmp(password,"12345")){
				  
                	jualsaham();
                	break;				
    			}   			
				else{
					
  					printf("\n\n  #  Silakan Login untuk menggunakan fitur ini.\n\n");
	                printf("\n > [Enter] untuk kembali.");
	                getch();
	                break;
 				}
			
			case 5:
				if(!strcmp(idakun,"sayurasem") && !strcmp(password,"12345")){
				  
                	searching();
                	break;				
    			}   			
				else{
					
  					printf("\n\n  #  Silakan Login untuk menggunakan fitur ini.\n\n");
	                printf("\n > [Enter] untuk kembali.");
	                getch();
	                break;
 				}
            case 6:
 				if(!strcmp(idakun,"sayurasem") && !strcmp(password,"12345")){
				  
                	tambahkurangdana();
                	break;				
    			}   			
				else{
					
  					printf("\n\n  #  Silakan Login untuk menggunakan fitur ini.\n\n");
	                printf("\n > [Enter] untuk kembali.");
	                getch();
	                break;
 				}

			case 7:
				updatepatch();
				break;				
            case 8:
				system("cls");
				printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
				printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
				printf("=======================================================  Keluar  =======================================================\n\n");
				
				puts("Apakah ingin keluar program?\t");
				puts("\n  [tekan 1] Keluar Program");
				puts("  [tekan 2] Kembali");
				puts("--------------------------------------");
				printf("	Pilihan: ");
				scanf("%d",&choice);
				switch(choice){
					case 1: 
					 	printf("\n\n  Loading");
					    for(i=0;i<=6;i++){
					        fordelay(100000000);
					        printf(".");
					    }
					    puts("\n\n  Program Selesai. Terima Kasih :)");
						exit(0);
						break;
					case 2:	
						system("pause");
						main();
						break;
					default:
						puts("\nMohon pilih pilihan yang benar (1-2).");
	  					getch();
                		break;	
				}                          
            default:
				puts("\nMohon pilih pilihan yang benar (0-7).");
	  			getch();
                break;
        }
    }
    return 0;
}

void help(){
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("======================================================  Bantuan  =======================================================\n\n");
	printf("   > Fitur Program:\n\t + Membeli saham\n\t  + Menjual saham\n\t   + Top-Up/tarik dana cash\n\t    + Melihat Portofolio\n\t");
	printf("     + Searching Emiten dan Sorting Portofolio\n\t      + Memperbarui Patch keamanan\n\t       + Melakukan Log in\n");
	printf("\n   > Program ini menggunakan:\n\t + Pointer\n\t  + Structures\n\t   + Malloc\n\t    + Union/Enum\n\t     + Linked List\n\t");
	printf("      + Queque\n\t       + Searching & Sorting\n\n");
	printf("\n===/ Menu Pengaturan Pengguna (Log-in) /====================\n");
	printf("   + Pada Menu ini pengguna akan diminta untuk memasukkan ID dan Passord serta \n");
	printf("     jumlah deposit awal untuk dimasukkan ke cash. Apabila terjadi kesalahan input\n");
	printf("     ID maupun Password, Pengguna akan diminta untuk mengulang input.\n");
	printf("\n===/ Menu Portofolio /======================================\n");
	printf("   + Pada menu ini, akan ditampilkan emiten serta harga emiten yang telah dibeli\n");
	printf("     pengguna.\n");
	printf("\n===/ Menu Beli Saham /======================================\n");
	printf("   + Pada menu ini, pengguna dapat membeli saham yang diinginkan. Program akan \n");
	printf("     menampilkan daftar bid dan offer beserta harganya.\n");
	printf("   + Caranya pembeliannya adalah dengan menginput emiten yang diinginkan, input \n");
	printf("     harga beli dan lot yang diinginkan.\n");
	printf("\n===/ Menu Jual Saham /======================================\n");
	printf("   + Pada menu ini, pengguna dapat menjual saham yang diinginkan. Program akan \n");
	printf("     menampilkan daftar bid dan offer beserta harganya.\n");
	printf("   + Caranya penjualannya adalah dengan menginput emiten yang diinginkan dan input \n");
	printf("     harga jual yang diinginkan.\n");
	printf("   + Selanjutnya akan ditampikan info terkait penjualan emiten tersebut.\n");
	printf("\n===/ Menu Top Up & Tarik dana /=============================\n");
	printf("   + Pada menu ini, Anda dapat melakukan top up maupun tarik dana dengan menginput\n");
	printf("     sejumlah nominal yang diinginkan.\n");
	printf("\n===/ Menu Search /=======================================\n");
	printf("   + Pada menu ini pengguna dapat mencari emiten yang telah dibeli sebelumnya.\n");
	printf("   + Untuk menginput data, masukkan nama emiten yang ingin dicari. Tekan enter, \n");
	printf("     maka program akan menampilkan hasil pencarian. Jika hasil ditemukan maka\n");
	printf("     program akan menampilkan emiten beserta harganya. Jika pencarian tidak\n");
	printf("     ditemukan, maka program akan menampilkan error handling.\n");
	printf("\n===/ Menu Update Patch /====================================\n");
	printf("   + Pada menu ini pengguna dapat mengupdate keamanan aplikasi dengan mengunduhnya.\n");
	printf("   + Pengguna juga dapat menguninstall patch terdahulu (awal) yang sudah usang\n");
	printf("   + Prinsip kerjanya adalah dengan menggunakan teknik queue, yaitu patch yang\n");
	printf("     pertama kali diinstall akan yang pertama diuninstall.\n");	
	printf("   + Program ini belum memiliki keamanan hingga pengguna menginstallnya.\n");
	printf("\n\n > [Enter] untuk kembali.");
	getch();	
}

void displaycash(){
		/*The account ID will display the user ID entered at login*/
		printf("\tID: %s\n", idakun);
		/*The value of cash will change if we deposit funds when logging into the account.
		  In addition, cash will decrease if the user buys shares according to the share price
                  and the lot. The cash value will increase if the user sells his shares above the price
                  buy (if sold profit), and will show minus results if the user sells
                  shares below the purchase price (loss)*/
 		printf("\tCash: Rp%d\n", cash);
 		/*If the cash value is minus due to the purchase of shares that exceeds the existing cash,
                  the program will display a notice that the user activates margin, that is, a loan
                  provided by the broker to the user. In t + 2 if the customer has not paid off the funds,
                  then you will be charged an interest fee of 2% minus the cash*/
 		if(cash < 0){
 			printf("\t * Anda mengaktifkan margin. Akan dikenakan bunga 2%% pada T+2 setiap harinya.");
		}
}


// function to provide loading delay
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

// function for account login
int dataawal(){
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("===================================================  Login Akun SAS  ===================================================\n\n");
	printf("  Masukkan ID:\n  >\t");
	scanf("%s", &idakun);

    printf("\n\n  Masukkan Password:\n  >\t"); 
	for(i=0;i<5;i++) 
  	{ 
   		password[i]=getch(); 
   		printf("*");   	 
  	} 
  	password[i]='\0'; 
  	
 	printf("\n\n\n [Enter] untuk Log in");
 	getch();
 	
 	if(!strcmp(idakun,"sayurasem") && !strcmp(password,"12345")) 
 	{ 
  		printf("\n\n\n\n  Mengonfirmasi akun ");
        for(i=0;i<=6;i++)
       	{
            fordelay(100000000);
              printf(".");
    	}
    }
	else{ 
  		printf("\n\n  #  Data yang Anda input tidak sesuai. Silakan ulangi.\n\n");
		system("pause");
		return dataawal();
 	}
 	printf("\n\n  #  Log In Berhasil!\n\n");
	system("pause");
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("===================================================  Login Akun SAS  ===================================================\n\n");
	printf("\n\n  Masukkan Saldo Awal:\n  >\tRp");
	scanf("%d", &cash);
}

void menuportofolio(){
	int choice;
	
 	if(!strcmp(idakun,"sayurasem") && !strcmp(password,"12345")){
				  
		system("cls");
		printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
		printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
		printf("=====================================================  PORTOFOLIO  =====================================================\n\n");
		// function to display account info compiled from initial data
		displaycash();
		// function to display portfolio
		portofolio();
		puts("\n\n  [tekan 1] Menyorting sesuai abjad");
		puts("  [tekan 2] Mencetak Portofolio ke file txt");
		puts("  [tekan 3] Kembali ke Menu Utama");
		puts("--------------------------------------");
		printf("	Pilihan: ");
		scanf("%d",&choice);
		switch(choice){
							
			case 1:
				sortnama();
				system("cls");
				printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
				printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
				printf("=====================================================  PORTOFOLIO  =====================================================\n\n");
				displaycash();
				portofolio();
				                
				printf("\n > [Enter] untuk kembali ke Menu Utama.");
				getch();
				main();
				break;
			case 2:
				cetakporto();
				getch();	                
			case 3:	
				system("pause");
				main();
				break;
								
			default:
				puts("\nMohon pilih pilihan yang benar (1-2).");
			  	getch();				
		        break;	
		} 					
    }
    			
	else{
					
  		printf("\n\n  #  Silakan Login untuk menggunakan fitur ini.\n\n");
	    printf("\n > [Enter] untuk kembali.");
	    getch();
 	}	
}

// function to display portfolio
void portofolio()
{
		struct node *ptr;
		
        if(start==NULL)
        {
                printf("\n\n  * Tidak ada saham yang tersimpan.\n");
        }
        else
        {
                ptr=start;
    			printf("\n\n\n\t== Portofolio ==\n");
				printf("\t----------------------------------------------------------------------------------------\n");
				printf("\t| Emiten	Value		Avg		Last		Pts(+/-)	   Lot |\n");
				printf("\t----------------------------------------------------------------------------------------\n");
                while(ptr!=NULL)
                {      
                	int i;

			   	printf("\t| %-10s	%-9d	%-5d		%-5d		%-9d	   %-4d|\n", ptr->emiten, ptr->info *100*ptr->lot, ptr->info, 2700, 2700*100*ptr->lot - (ptr->info *100*ptr->lot), ptr->lot);
                        ptr=ptr->next ;
                }
                printf("\t----------------------------------------------------------------------------------------\n");
                /*In the appearance of this table, the data on the shares that have been purchased are displayed. If buying shares, then
                  will add rows to the bottom of the table. If you sell stock, the selected line will be deleted
                  from the table that shows the stock is no longer in the portfolio. The value 2700 indicates the price
                  current stocks which are assumed to be static follow the JCI value. If the purchase price is less than the current price,
                  then Pts will show the plus (profit) according to the calculation. If the price of the shares purchased is more than the price
                  now indicates minus Pts (loss) according to the calculation. Note that the value changes in price
                  in this table is floating (profit / loss) which will not add / reduce cash before
                  the shares are sold.*/
        }
}

void cetakporto(){
	struct node *ptr;
	FILE *fptr;

   	fptr = fopen("C:\\Portofolio Kelompok Sayur Asem.txt","w");

   	if(fptr == NULL)
   	{
      	printf("Error!");   
      	exit(1);             
   	}
	ptr=start;
	
    fprintf(fptr, "\n\n\n\t== Portofolio ==\n");
	fprintf(fptr, "\t----------------------------------------------------------------------------------------\n");
	fprintf(fptr, "\t| Emiten	Value		Avg		Last		Pts(+/-)	   Lot |\n");
	fprintf(fptr, "\t----------------------------------------------------------------------------------------\n");
                while(ptr!=NULL)
                {      
                	int i;

			   		fprintf(fptr, "\t| %-10s	%-9d	%-5d		%-5d		%-9d	   %-4d|\n", ptr->emiten, ptr->info *100*ptr->lot, ptr->info, 2700, 2700*100*ptr->lot - (ptr->info *100*ptr->lot), ptr->lot);
                	ptr=ptr->next ;
                }
   	fprintf(fptr, "\t----------------------------------------------------------------------------------------\n");
   	fclose(fptr);

   	getch();	
}

// menu function to buy shares
void belisaham(){
	int ch;	
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("=====================================================  BELI SAHAM  =====================================================\n\n");
 	
	puts("\n\n [tekan 1] Untuk beli saham");
 	puts(" [tekan 2] Kembali ke Menu Utama");
    printf("\n--------------------------------------\n");
    printf("  Pilihan:\t");
 	scanf("%d",&ch);
 	
	switch(ch)
	{
  	case 1:insert_end();
		main();
		break;
  	case 2:main();
		break;
  	default:puts("  * Mohon pilih pilihan yang benar (1-2).");
		getch();
		main();
 	}
}

// the function to buy shares
void insert_end()
{
	int ch;	
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("=====================================================  BELI SAHAM  =====================================================\n\n");

    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    
    if(temp==NULL)
    {
        printf("\nMemori tidak cukup\n");
        return;
    }
    
    printf("\n  Emiten yang ingin dibeli:\n\t>  " );
    scanf("%s",&temp->emiten );
    
    randomharga(temp->emiten);
    printf("\n\n\t>  Harga saat ini adalah: %d", num*10);
	
	puts("\n\n  Ingin Beli?\n  [tekan 1] untuk beli");
 	puts("  [tekan 2] untuk kembali ke menu utama");
    printf("--------------------------------------\n");
    printf("  Pilihan:\t");
 	scanf("%d",&ch);
 	switch(ch){
 		
  	case 1:
  		printf("\n  masukkan harga yang ingin dibeli:\n\t>  ");
		scanf("%d",&temp->info );
		    
		printf("\n  berapa lot:\n\t>  ");
		scanf("%d", &temp->lot);
		
		temp->next =NULL;   
		if(start==NULL){
		    start=temp;
		}
		else{
			ptr=start;
		    while(ptr->next !=NULL){
		        ptr=ptr->next ;
		    }
		    ptr->next =temp;
		}
		cash = cash - temp->info *100*temp->lot;
		system("pause");
		break;
		
  	case 2:
	  	main();
		break;
		
  	default:puts("  * Mohon pilih pilihan yang benar (1-2).");
		getch();
		insert_end();
 	}
}

// function to randomize the share buy price
int randomharga(int key)
{
	int i;
    int lower = 100, upper = 500, count = 1;

    srand(time(0));
    printf("\n\n  Harga %s hari ini: ", key);
    
    for (i = 0; i < count; i++) {
        num = (rand() % (upper - lower + 1)) + lower;
        printf("\n\n\t----------------");
        printf("\n\t|Price   | Vol |");
        printf("\n\t----------------");
        printf("\n\t| %-6d |1003 | <-- Offer", (num*10)+20);
        printf("\n\t| %-6d |200  | <-- Offer", (num*10)+10);
        printf("\n\t| %-6d |7890 | <-- ( Posisi saat ini )", (num*10));
        printf("\n\t| %-6d |86030| <-- Bid", (num*10)-10);
        printf("\n\t| %-6d |10090| <-- Bid", (num*10)-20);
		printf("\n\t----------------");               			   
    }
    return num;
}

// function to randomize the sell price of the stock
int randomharga1(int key)
{
	int i;	
    int lower = 300, upper = 500, count = 1;	\
    srand(time(0));
    printf("\n\n  Harga saham No. %d hari ini: ", key);
    
    for (i = 0; i < count; i++) {
        num = (rand() % (upper - lower + 1)) + lower;	
        printf("\n\n\t----------------");
        printf("\n\t|Price   | Vol |");
        printf("\n\t----------------");
        printf("\n\t| %-6d |21003| <-- Offer", (num*10)+20);
        printf("\n\t| %-6d |4980 | <-- Offer", (num*10)+10);
        printf("\n\t| %-6d |120  | <-- ( Posisi saat ini )", (num*10));
        printf("\n\t| %-6d |1120 | <-- Bid", (num*10)-10);
        printf("\n\t| %-6d |2890 | <-- Bid", (num*10)-20);
		printf("\n\t----------------");               			   
    }
    return num;
}

// menu function sells stocks
void jualsaham()
{
	int ch;		
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("=====================================================  Jual Saham  =====================================================\n\n");
 	
	puts("\n\n [tekan 1] Untuk menjual saham");
 	puts(" [tekan 2] Kembali ke Menu Utama");
    printf("\n--------------------------------------\n");
    printf("  Pilihan:\t");
 	scanf("%d",&ch);
 	
	switch(ch)
 	{
	 	case 1:
		 	delete_pos();
	 		main();
	 		break;
  		case 2:
		  	main();
	 		break;
  		default:
		  	puts("  * Mohon pilih pilihan yang benar (1-2).");
		  	printf("\n\n > [Enter] untuk kembali.");
	  		getch();
	  		jualsaham();
 	}
}

// function to sell shares
void delete_pos()
{
    int i,pos, ch;  	
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
        
    system("cls");
    printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("=====================================================  Jual Saham  =====================================================\n\n");
    displaycash();
        
	if(start==NULL)
    {
        portofolio();
        printf("\n  * Tidak ada saham yang tersimpan.\n");
    }
    else
    {	
        portofolio();
        printf("\n  * Urutan saham diurutkan dari 0 hingga baris terakhir. No. 0 adalah baris teratas tabel (baris ke 1).");
        printf("\n    No. 1 menunjukkan baris ke 2, No. 3 menunjukkan baris ke 3, dst.");
        printf("\n  > Masukkan No. saham yang akan dijual:\n\tSaham No.");
        scanf("%d",&pos);
            
        system("cls");
        printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
		printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
		printf("=====================================================  Jual Saham  =====================================================\n\n");
        displaycash();
        	
        randomharga1(pos);
        printf("\n\n\t>  Harga saat ini adalah: %d", num*10);
            
        puts("\n\n  Ingin Jual?\n  [tekan 1] untuk jual");
 		puts("  [tekan 2] untuk kembali ke menu utama");
    	printf("--------------------------------------\n");
    	printf("  Pilihan:\t");
 		scanf("%d",&ch);
 		switch(ch)
		{
  			case 1:    
            	printf("\n\n  >  Harga Jual yang diinginkan: ");
            	scanf("%d", &jual);
            
            	if(pos==0){
                	ptr=start;
                	start=start->next ;
                
                	printf("\n  * Saham yang dijual adalah %s dengan harga beli %d (%d Lot)",ptr->emiten, ptr->info, ptr->lot  );
                	printf("\n    Saham telah terjual dengan harga jual: %d (%d Lot)", jual, ptr->lot  );
                	printf("\n  * Profit/Loss: Rp%d", jual*ptr->lot*100 - ptr->info*ptr->lot*100);
                	free(ptr);
            	}
        		else{
                	ptr=start;
                	for(i=0;i<pos;i++){ 
						temp=ptr; ptr=ptr->next ;
                    	if(ptr==NULL)
                    	{
                       		printf("\n  * Tidak ada Saham pada No. tersebut. Silakan ulangi.\n");
                        	getch();
                        	return;
                    	}
                	}
                	temp->next =ptr->next ;
                	printf("\n  * Saham yang dijual adalah %s dengan harga beli %d (%d Lot)",ptr->emiten, ptr->info, ptr->lot  );
                	printf("\n    Saham telah terjual dengan harga jual: %d (%d Lot)", jual, ptr->lot  );
                	printf("\n  * Profit/Loss: Rp%d", jual*ptr->lot*100 - ptr->info*ptr->lot*100);
                	free(ptr);
            	}
            	cash = cash + jual*ptr->lot*100;
				break;
            case 2:
            	main();
            	break;
            default:
            	puts("  * Mohon pilih pilihan yang benar (1-2).");
				getch();
				delete_pos();   	
        }
    	printf("\n\n > [Enter] untuk kembali ke Menu Utama.");
    	getch();
	}
}

void searching(){
	
 	struct node *t;
 	char dump[10];
 	char cariemiten[10];
 	int found=0, chc;
 	int searchcount=1;
 	if(start==NULL){
  		printf("\n  *  Tidak ada saham yang tersimpan\n");
  		return;
 	}
 	for(;;){
 		
 		gets(dump);
	   	printf("\n  Masukkan nama emiten yang ingin dicari: \n\t  >  ");
	   	scanf("%s", cariemiten);
	   	
	   	t=start;
	   
		while(t!=NULL){
		    if(strcmp(t->emiten, cariemiten)==0){
		     	found=1;
		     	break;
		    }
		    t=t->next;
	   	}
	  	if(found==1){
	   		printf("\n");
	   		printf("  Emiten |   Harga    |  Lot |\n");
	   		printf("  %-4s   | %10d | %4d |\n\n", t->emiten, t->info, t->lot);
	   		system("pause");
	   		break;
	  	}
	  	else if(found != 1){
	   		printf("\n  Emiten tidak ada dalam data\n\n");
	   		system("pause");
	   		break;
	  	}
 	}
}

// Cash Top Up function
void tambahkurangdana(){
	
	int ch, topup, tarikdana;
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("=====================================================  Top Up Cash  ====================================================\n\n");
	displaycash();
	
 	puts("\n\n[tekan 1] Top-up Cash\n");
 	puts("[tekan 2] Tarik Dana Cash\n");
 	puts("[tekan 3] Menu Utama\n");
    puts("--------------------------------------");
    printf("  Pilihan: ");
 	scanf("%d",&ch);
 	
 	switch(ch)
 	{
	 	case 1:printf("\n  Masukkan jumlah top-up:\n  >\tRp");	
	 		scanf("%d",&topup);
	 		cash = cash + topup;		
	 		printf("\n\n  Memproses Top-Up");
        	for(i=0;i<=6;i++)	
       		{
            	fordelay(100000000);
              	printf(".");
        	}
	 		printf("\n\n  >  Top-up Berhasil!\n\n");
	 		system("pause");
	 		main();
	 		break;
	 	case 2:
		 	printf("\n  Masukkan cash yang ingin ditarik:\n  >\tRp");
	 		scanf("%d", &tarikdana);
	 		cash = cash - tarikdana;
	 		if(cash < 0) 
 			{ 
  				printf("\n\n  * Mohon maaf nilai yang ditarik melebihi cash Anda");
  				printf("\n    Silakan masukkan nominal yang benar.\n");
  				cash = cash + tarikdana;					
  				printf("\n\n > [Enter] untuk kembali");
  				getch();
				tambahkurangdana();						
    		}
    		printf("\n\n  Memproses Tarik Dana");
        	for(i=0;i<=6;i++)								
       		{
            	fordelay(100000000);
              	printf(".");
        	}
	 		printf("\n\n  >  Tarik Dana Berhasil!\n\n");
	 		system("pause");
	 		main();
	 		break;
  		case 3:main();
	 		break;
  		default:puts("  Mohon pilih pilihan yang benar (1-3).");
  			printf("\n\n > [Enter] untuk kembali.");
  			getch();
	  		tambahkurangdana();
 	}
}

// issuer name sorting function
void sortnama(){
	
 	struct node *t;
 	struct node *temp=NULL;
 	int swapped;
 
 	if(start==NULL){
  		printf("\n  *  Tidak ada saham yang tersimpan.\n");
  		return;
 	}
 	do{
  		swapped=0;
  		t=start;
  		while(t->next!=temp){
   			if(strcmp(t->emiten,(t->next->emiten))>0){
    			swap(t,t->next);
    			swapped=1;
   			}
   			t=t->next;
  		}
  		temp=t;
 	}
 	while (swapped);
}

// swap function for sorting
void swap(struct node *a, struct node *b){
 	
	char tempemiten[10];
	int tempinfo;
	int templot;
 
 	strcpy(tempemiten, a->emiten);
 	strcpy(a->emiten, b->emiten);
 	strcpy(b->emiten, tempemiten);
 	
 	tempinfo = a->info;
 	a->info = b->info;
 	b->info = tempinfo;
 	
 	templot = a->lot;
 	a->lot = b->lot;
 	b->lot = templot;	
}

// function to update the application
void updatepatch(){
	int pilihan;				
	char nama[20];				
	
	system("cls");
	printf("\n                                             =$$  Sayur Asem Sekuritas  $$=\n");
	printf("                                                 ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("================================================  Update Patch Keamanan  ===============================================\n\n");
	printQueue1(headPtr1);			
	puts("Masukan pilihan Anda:\n");
	printf(" [tekan 1] Untuk Meng-install Patch terbaru\n\n [tekan 2] Untuk Uninstall patch terdahulu\n\n");
	printf(" [tekan 3] Kembali ke Menu Utama");	
    puts("\n\n--------------------------------------");
    printf("  Pilihan: ");
	scanf("%d", &pilihan);
	while(pilihan!=6){
		switch(pilihan){
			case 1:			
				printf("\n\n  >  Patch keamanan yang ingin di-install: \n\t");
				scanf("%s", &nama);
				
				enQueue1(&headPtr1, &tailPtr1, nama);
				
				printf("\n\n  Meng-install Patch ");
	        	for(i=0;i<=6;i++)
	       		{
	            	fordelay(100000000);
	              	printf(".");
	        	}
		 		printf("\n\n  >  Patch Ter-install!\n\n");
				system("pause");
				system("cls");								
				break;
			case 2:						
				if(!isEmpty1(headPtr1)){
					deQueue1(&headPtr1, &tailPtr1);
				}
				printf("\n\n  Meng-uninstall Patch ");
	        	for(i=0;i<=6;i++)
	       		{
	            	fordelay(100000000);
	              	printf(".");
	        	}
		 		printf("\n\n  >  Patch Ter-uninstall!\n\n");
				system("pause");
				system("cls");								
				break;
			case 3:						
				main();
				break;
			default:
				puts("\n  Mohon pilih pilihan yang benar (1-3).");
				system("pause");
				system("cls");				
				break;
		}
		updatepatch();
	}
}

// the function of adding patches to the queue
void enQueue1(PembaruanPtr *headPtr1, PembaruanPtr *tailPtr1, char nama[20]){
	PembaruanPtr newPtr1;
	
	newPtr1 = malloc(sizeof(Pembaruan));
	
	if(newPtr1 != NULL){
		strcpy(newPtr1->patch, nama);
		newPtr1->next = NULL;
					
		if(isEmpty1(*headPtr1)){
			*headPtr1 = newPtr1;
		}
		else{
			(*tailPtr1)->next = newPtr1;
		}
		*tailPtr1 = newPtr1;
	}
	else{
		printf("%s tidak dimasukan ke antrian. Karena antrian sudah full.", newPtr1->patch);
	}
}

// function reduces queue patches, removes the earliest added patches
void deQueue1(PembaruanPtr *headPtr1, PembaruanPtr *tailPtr1){
	char nama[20];												
	PembaruanPtr tempPtr1;
	
	strcpy(nama, (*headPtr1)->patch);									
	tempPtr1 = *headPtr1;
	*headPtr1 = (*headPtr1)->next;
	
	if(*headPtr1 == NULL){
		*tailPtr1 == NULL;
	}
	
	free(tempPtr1);
	
	printf("\n  >  Patch keamanan [%s] akan di-uninstall.\n", strupr(nama));
	system("pause");
}

// function to check whether headptr is null or not, if it is null then the value will be the headptr
int isEmpty1(PembaruanPtr headPtr1){		
	return headPtr1 == NULL;
}

// displays security info
void printQueue1(PembaruanPtr currentPtr1){
	if(currentPtr1 == NULL){									
		printf("  >  Patch keamanan Ter-install: \n\tBelum ada.\n\n\n");
	}
	else{															
		printf("  >  Patch keamanan saat ini: \n");
		while(currentPtr1 != NULL){
			printf("\t%s\n", strupr(currentPtr1->patch));
			currentPtr1 = currentPtr1->next;
		}
		printf("\t ^ (patch saat ini)\n");
		printf("\n\n\n");
	}
}
//end
