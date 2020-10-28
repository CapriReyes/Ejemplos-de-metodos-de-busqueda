#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

void menu();
void buscar(int arreglo[],int n, int b);
void secuencial(int arreglo[],int n,int b);
void binaria(int arreglo[],int n,int b,int t);
void hashing(int arreglo[],int n,int tablah[],int n2);
void arregloE(int arreglo[],int n);
void imprimir(int arreglo[],int n);
void buscarHashing(int tablah[],int n,int k,int b);

int main(){
	menu();
	system("pause");
	return 0;
}

void menu(){
	int eleccion, n=10,array[n],buscar,key=0;
	int tablah[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	do{
		system("cls");
		cout<<"\t\t\t\t\t\t\t\tMenu\n"	
			<<"\t\t\t\t\t\t\t\t1.-Crear un arreglo de enteros\n"
			<<"\t\t\t\t\t\t\t\t2.-Busqueda Secuencial\n"
			<<"\t\t\t\t\t\t\t\t3.-Busqueda Binaria\n"
			<<"\t\t\t\t\t\t\t\t4.-Busqueda Hashing\n"
			<<"\t\t\t\t\t\t\t\tEleccion--->";
		cin>>eleccion;
		system("cls");
		switch(eleccion){
			case 1:{
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\tIntroduce el tamanio del arreglo:";
				cin>>n;
				arregloE(array,n);
				imprimir(array,n);
				hashing(array,n,tablah,n);
				imprimir(tablah,10);
				break;
			}
			case 2:{
				cout<<"\t\t\t\t\t\t\t\tIntroduce el Dato a buscar:";
				cin>>buscar;
				secuencial(array,n,buscar);
				break;
			}
			case 3:{
				cout<<"\t\t\t\t\t\t\t\tIntroduce el Dato a buscar:";
				cin>>buscar;
				binaria(array,n,buscar,n);
				break;
			}
			case 4:{
				cout<<"\t\t\t\t\t\t\t\tIntroduce el Dato a buscar:";
				cin>>buscar;
				key=buscar%10;
				buscarHashing(tablah,n,key,buscar);
				break;
			}
		}	
	}while(eleccion!=0);
}

void buscarHashing(int tablah[],int n,int k,int b){
	system("cls");
	if(k==10){
		cout<<"\t\t\t\t\t\t\t\tNo se encontro el dato\n";
		return;
	}
	if(tablah[k]==b){
		cout<<"\t\t\t\t\t\t\t\tvalor encontrado\n";
	}else{
		buscarHashing(tablah,n,k+1,b);
	}
	system("pause");
}

void buscar(int arreglo[],int n,int b){
	int inferior=0, superior=n, mitad;
	bool V=false;
	do{
		mitad=(inferior+superior)/2;
		if(arreglo[mitad]==b){
			cout<<"\t\t\t\t\t\t\t\tElemento "<<b<<" ha sido encontrado en el arreglo";
			V=true;
		}
		if(arreglo[mitad]>b){
			superior=mitad;
			mitad=(inferior+superior)/2;
		}
		if(arreglo[mitad<b]){
			inferior=mitad;
			mitad=(inferior+superior)/2;
		}
	}while(!V&&inferior<=superior);
	
}

void secuencial(int arreglo[],int n,int b){
	int pos=0;
	bool V=false;
	do{
		if(arreglo[pos]==b){
			cout<<"\t\t\t\t\t\t\t\tElemento "<<b<<" encontrado en la posicion "<<pos+1<<endl;
			V=true;
		}
		if(pos==n){
			cout<<"\t\t\t\t\t\t\t\tElemento "<<b<<" No encontrado\n";
			V=true;
		}
		pos++;
	}while(!V);
	system("pause");
}

void binaria(int arreglo[],int n,int b,int t){
	int aux;
	int ordenado[n];
	for(int i=0;i<n;i++){
		ordenado[i]=arreglo[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ordenado[j+1]>0){
				if(ordenado[j]>ordenado[j+1]){
					aux=ordenado[j];
					ordenado[j]=ordenado[j+1];
					ordenado[j+1]=aux;	
				}
			}
		}
	}
	buscar(ordenado,n,b);
}

void hashing(int arreglo[],int n,int tablah[],int n2){
	int indice;
	for(int i=0;i<10;i++){
		indice=arreglo[i]%10;
		cout<<indice<<endl;
		while(tablah[indice]!=NULL){
			indice++;
		}
		tablah[indice]=arreglo[i];
	}
}

void arregloE(int arreglo[],int n){
	for(int i=0;i<n;i++){
		cout<<"\t\t\t\t\t\t\t\tIntroduce el dato de la posicion "<<i+1<<": ";
		cin>>arreglo[i];
	}
}

void imprimir(int arreglo[],int n){
	system("cls");
	cout<<"\t\t\t\t\t\t\t\tArreglo introducido\n";
	for(int i=0;i<n;i++){
		cout<<"\t\t\t\t\t\t\t\t"<<i+1<<"---->"<<arreglo[i]<<"\n";
	}
	system("pause");
}



