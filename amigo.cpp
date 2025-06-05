#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    
    SetConsoleOutputCP(65001) ;
    
    double FundoDeCaixa = 0;
    cout << "Defina um valor para inicializar o caixa" << endl;
    cin >> FundoDeCaixa ;
    while (FundoDeCaixa <= 0) {
        cout << "Valor invalido, digite novamente\n" ; 
        cin >> FundoDeCaixa ;
    }
    cout << "Valor iniciado em: " << FundoDeCaixa << endl << endl;
    double FundoDeCaixaPrim = FundoDeCaixa ;

    // MENU VAI AQUI

    double valor = 0;
    int quantidade = 0;
    double valorVenda = 0;
    double troco = 0;
    double trocoTotal = 0;
    double valorCaixa = 0 ;
    double pagamento = 0;
    int vendaRealizada = 0;
   

    double ultimaVenda = 0;
    double ultimaQtd = 0;
    double ultimoTroco = 0;
    double ultimoPagamento = 0;


    int opc ;
    bool continuar = true;
    do {
    cout << "Digite 1 para vender.\n" ;
    cout << "Digite 2 para registro de vendas.\n" ;
    cout << "Digite 3 fechamento de caixa.\n\n" ;
    cin >> opc ;
    switch (opc) {
    case 1: {
        // registro de vendas
        bool vendas = true ;
        double valorTotal = 0 ;
        do {
            cout << "Digite o valor do produto a ser vendido.\n" ;
            cin >> valor ;
            while (valor <= 0) {
              cout << "Valor invalido, digite novamente\n" ; 
              cin >> valor ; }
            cout << "Digite a quantidade de produtos a ser vendida.\n" ;
            cin >> quantidade ;
            while (quantidade <= 0) {
              cout << "Valor invalido, digite novamente\n" ; 
              cin >> quantidade ; }

            valorVenda = quantidade * valor ;
            valorTotal += valorVenda ;

            cout << "Valor registrado de: " << valorVenda << endl ;
    
            cout << "Deseja adicionar outro produto? (S/N)\n" ;
            char verificador ;
            cin >> verificador ;             
            switch(verificador) {
                case 's':
                continue ;
                case 'S':
                continue;
                case 'n':
                vendas = false ;
                break;
                case 'N':
                vendas = false ;
                break;

            }

        } while (vendas == true) ;

        cout << "Valor de venda total de: " << valorTotal <<". Insira o valor do pagamento.\n" ;
        cin >> pagamento ;
        while(pagamento < valorTotal) {
            cout << "Erro. Valor de pagamento insuficiente, digite novamente.\n" ;
            cin >> pagamento ;
        }
        if(pagamento > valorTotal) {
            troco = pagamento - valorTotal ;
            while(troco > FundoDeCaixa) {
                cout << "Erro. O valor do troco é maior que o valor do caixa, digite novamente.\n" ;
                cin >> pagamento ;
                troco = pagamento - valorTotal ;
            }
            cout << "\nVenda realizada com sucesso no valor de: " << valorTotal << "R$.\n" ;
            
            trocoTotal += troco ;
            valorCaixa += pagamento ;
            valorCaixa -= troco ;
            FundoDeCaixa += valorCaixa ;
            vendaRealizada++ ;

            cout << "Seu troco foi de: " << troco << "R$ para um pagamento de: " << pagamento << "R$\n\n" ;
            break;            
        }

        if(pagamento == valorTotal) {
            cout << "\nVenda realizada com sucesso no valor de: " << valorTotal << "R$.\n" ;
            valorCaixa += pagamento ;
            FundoDeCaixa += valorCaixa ;
            vendaRealizada++ ;
            break;

        } 
    }
    case 2: {
    // comprovante 

    
    if(vendaRealizada != 0) {

    ultimaVenda = valorVenda ;
    ultimaQtd = quantidade ;
    ultimoTroco = troco ;
    ultimoPagamento = pagamento ;


    cout << "Comprovante da ultima venda: " << endl ;
    cout << "Subtotal da venda: R$" << ultimaVenda << endl ;
    cout << "Quantidade de produtos vendidos: " << ultimaQtd << endl ;
    cout << "Pagamento realizado: R$" << pagamento << endl ;
    cout << "Troco realizado: R$" << ultimoTroco << endl; 
} else {
    cout << "Nenhuma venda realizada.\n" ;
}

    break; 
    }

    case 3: {
    // terminar caixa exibir valores

    cout << "fechamento de caixa." << endl ;
    cout << "Valor iniciado no caixa: R$" << FundoDeCaixaPrim << endl;
    cout << "Total de vendas feitas: " << vendaRealizada << endl;
    cout << "Total de entradas: R$" <<  valorCaixa << endl;
    cout << "Total de saidas em troco: R$" << trocoTotal << endl; 
    cout << "Valor total bruto: R$" << FundoDeCaixaPrim + valorCaixa << endl;

    continuar = false ;
    break;
    }

    default: {
     cout << "Numero digitado invalido. Digite novamente.\n" ; 
     cin >> opc ; }
     
    } 

} while(continuar == true) ;

cout << "Obrigado por usar nosso sistema de caixa!" << endl ;

    return 0;
}

