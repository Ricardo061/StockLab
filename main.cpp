/* =======================================================================================================
 *
 * Arquivo principal main.cpp
 * 
 *  STOCKLAB - Programa local para controle de Estoque! 
 * 
 * Author: Joao Ricardo Chaves
 * Date: 03/06/25
 * 
 * =======================================================================================================
 */ 

// ================================
// --- Libraries ---
#include "includes.hpp"
#include "registercomp.hpp"
#include "users.hpp"

// ======================================
// --- Macros/Constants and Objects ---
Users UserSystem;
Registercomp NewComp;

// ================================
// --- Function Prototypes ---
void printAscii();   // Imprime Imagem Ascii
void bootSystem();   // Inicializa o boot do sistema
void bootLogin();    // BootLogin
void loadingBar();   // Barra de Progressao 

// ================================
// --- Main Function ---

int main(void)
{
    char opt,optLogin,optRegis;
    string Username, Password, 
           Name, Category,
           Value,description,optionLogin;
    double price;
    bool verification;
    int VarCont=0,ID=0,QTD=0;
    
    do
    {
        system("clear");
        printAscii();
        bootLogin();
        cin >> optLogin;

        switch(optLogin)
        {
            case '1':
                system("clear");
                printAscii();
                cout << "StockLab - Login ";
                cout << "\nUsername: ";
                cin  >> Username;
                cout << "Password: ";
                system("stty -echo");
                cin  >> Password;
                system("stty echo");
                verification = UserSystem.autentic(Username,Password);
                if(verification)
                {
                    VarCont = 0;
                    cout << "\nLogin Succesfull!" << endl;
                    loadingBar();
                    do
                    {
                        system("clear");
                        printAscii();
                        bootSystem();
                        cin >> opt;

                        switch (opt)
                        {
                        case '1':
                            do
                            {
                                system("clear");
                                printAscii();
                                cout << " ..:Modify Product:.. " << endl;
                                NewComp.ModifyProduct();

                                cout << "\nDeseja modificar outro produto ? (y/n): ";
                                cin >> optRegis;
                                optRegis = toupper(optRegis);
                                cout << endl;
                            } while (optRegis != 'N');
                            break;
                        case '2':
                            do
                            {
                                system("clear");
                                printAscii();
                                cout << " ..:Remove Product:.. " << endl;
                                NewComp.RemoveProduct();

                                cout << "\nDeseja remover outro produto ? (y/n): ";
                                cin >> optRegis;
                                optRegis = toupper(optRegis);
                                cout << endl;
                            } while (optRegis != 'N');
                            
                            break;
                        case '3':
                            do
                            {
                                system("clear");
                                printAscii();
                                cout << " ..:Register Product:.. " << endl;
                                cout << "ID Product: ";
                                cin >> ID;
                                NewComp.SetID(ID);
                                cout << "Name Product: ";
                                cin >> Name;
                                NewComp.SetName(Name);
                                cout << "Category: ";
                                cin >> Category;
                                NewComp.SetCategory(Category);
                                cout << "Amount: ";
                                cin >> QTD;
                                NewComp.SetQuantidade(QTD);
                                cout << "Price: ";
                                cin >> price;
                                NewComp.SetPrice(price);
                                cout << "Description: ";
                                cin >> description;
                                NewComp.SetDescription(description);

                                NewComp.RegisterComponent();
                                
                                cout << GREEN << "\nProduto cadastrado com Sucesso!\n" << RESET;

                                cout << "Deseja cadastrar outro produto ? (y/n): ";
                                cin >> optRegis;
                                optRegis = toupper(optRegis);
                                cout << endl;
                            } while (optRegis != 'N');
                            break;
                        case '4':
                            do
                            {
                                system("clear");
                                printAscii();
                                cout << setw(50) <<  " +--------------+\n"
                                << setw(50) <<    "  |..:StockLab:..|\n"
                                << setw(49) <<    "+--------------+" << endl;
                                NewComp.LoadStock();
                                cout << "\nDeseja sair? (y/n): ";
                                cin >> optRegis;

                                optRegis = toupper(optRegis);
                            } while (optRegis != 'Y');

                            break;
                        case '5':
                            cout << "5 " << endl;
                            exit(2);
                            break;
                        default:
                            cout << "Invalid Command!" << endl;
                            break;
                        }// end Switch case
                    }while(opt != '5');
                }//end if
                else
                {
                    cerr << RED << "\nInvalid Username or Password!" << RESET << endl;
                    cerr << "Try Again [" << VarCont+1<<"/3]";
                    VarCont++;
                    if(VarCont>=3) 
                    {
                        cerr << RED << "\nToo many failed attempts. Exiting..." << RESET << endl;
                        exit(3);
                    }//end if aninhado
                    system("sleep 1.50");
                }//end else
                break;
            case '2':
                system("clear");
                printAscii();
                cout << "StockLab - Register Account ";
                cout << "\nUsername: ";
                cin  >> Username;
                cout << "Password: ";
                system("stty -echo");
                cin  >> Password;
                system("stty echo");

                UserSystem.SetLogin(Username);
                UserSystem.SetPassword(Password);
                UserSystem.RegisterUser();
                cout << RESET;
                system("sleep 1");
                break;
            case '3':
                exit(1);
                break;
            default:
                cout << RED << " Invalid Command!" << RESET << endl;
                break;
        }// edn switch case
    }while(optLogin != '3');
    return 0;
}// end main function

// ================================
// --- Functions ---

// ================================
// --- PrintAscii ---
void printAscii() 
{
    const int terminalWidth = 120;
    const int artWidth = 70;  
    int indent = (terminalWidth - artWidth) / 2;

    cout << GREEN;
    cout << setw(indent) << "" << "                         __    _                          \n";
    cout << setw(indent) << "" << "                    _wr\"\"        \"-q__                    \n";
    cout << setw(indent) << "" << "                 _dP                 9m_                  \n";
    cout << setw(indent) << "" << "               _#P                     9#_                \n";
    cout << setw(indent) << "" << "              d#@                       9#m               \n";
    cout << setw(indent) << "" << "             d##                         ###              \n";
    cout << setw(indent) << "" << "            J###                         ###L             \n";
    cout << setw(indent) << "" << "            {###K                       J###K             \n";
    cout << setw(indent) << "" << "            ]####K      ___aaa___      J####F             \n";
    cout << setw(indent) << "" << "        __gmM######_  w#P\"\"   \"\"9#m  _d#####Mmw__         \n";
    cout << setw(indent) << "" << "     _g##############mZ_         __g##############m_      \n";
    cout << setw(indent) << "" << "   _d####M@PPPP@@M#######Mmp gm#########@@PPP9@M####m_    \n";
    cout << setw(indent) << "" << "  a###\"\"          ,Z\"#####@\" '######\"\\g          \"\"M##m   \n";
    cout << setw(indent) << "" << " J#@\"             0L  \"*##     ##@\"  J#              *#K  \n";
    cout << setw(indent) << "" << " #\"               `#    \"_gmwgm_~    dF               `#_ \n";
    cout << setw(indent) << "" << "7F                 \"#_   ]#####F   _dK                 JE \n";
    cout << setw(indent) << "" << "]                    *m__ ##### __g@\"                   F \n";
    cout << setw(indent) << "" << "                       \"PJ#####LP\"                        \n";
    cout << setw(indent) << "" << " `                       0######_                      '  \n";
    cout << setw(indent) << "" << "                       _0########_                        \n";
    cout << setw(indent) << "" << "     .               _d#####^#####m__              ,      \n";
    cout << setw(indent) << "" << "      \"*w_________am#####P\"   ~9#####mw_________w*\"       \n";
    cout << setw(indent) << "" << "          \"\"9@#####@M\"\"           \"\"P@#####@M\"\"           \n\n";
    cout << "                                                                            \n\n";
    cout << "                                                                           © 2025 - Joao Ricardo Chaves\n";
    cout << "=========================================================================================================" << endl;
    cout << RESET;
}// end printAscii


   

// ================================
// --- BootSystem ---
void bootSystem()
{
    cout << " ..:StockLab:.. \n";
    cout << "(1) - Modify Product\n";
    cout << "(2) - Remove Product\n";
    cout << "(3) - Register New Product\n";
    cout << "(4) - View Stock\n";
    cout << "(5) - Exit" << endl;
    cout << "Input Command: ";
} //end bootSystem

// ================================
// --- Tela Login ---
void bootLogin()
{
    cout << " ..:StockLab:.. " << endl;
    cout << "(1) - Login Account" << "\n";
    cout << "(2) - Register Account" << "\n";
    cout << "(3) - Exit " << endl;
    cout << "Input Command: ";
}// end BootLogin

// ================================
// --- LoadingBar ---
void loadingBar()
{
    const int total = 15;
    cout << BLUE;
    cout << "\nLoading[";
    for(int i = 0; i<total ; i++)
    {
        cout << "\rLoading: [";

        for (int j = 0; j < i; j++) 
            cout << "▓";

        for (int j = i; j < total; j++) 
            cout << "░";

        int percent = (i * 100) / total;
        cout << "] " << percent << "%";
        cout.flush();
        system("sleep 0.1");
    }// end for
    cout << RESET;
}// end LoadingBar













// ================================
// --- End Of File ---

//=======================================================================================================
//
//     ██╗██████╗     ███████╗██╗     ███████╗ ██████╗████████╗██████╗  ██████╗ ███╗   ██╗██╗ ██████╗
//     ██║██╔══██╗    ██╔════╝██║     ██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗████╗  ██║██║██╔════╝
//     ██║██████╔╝    █████╗  ██║     █████╗  ██║        ██║   ██████╔╝██║   ██║██╔██╗ ██║██║██║     
//██   ██║██╔══██╗    ██╔══╝  ██║     ██╔══╝  ██║        ██║   ██╔══██╗██║   ██║██║╚██╗██║██║██║     
//╚█████╔╝██║  ██║    ███████╗███████╗███████╗╚██████╗   ██║   ██║  ██║╚██████╔╝██║ ╚████║██║╚██████╗
// ╚════╝ ╚═╝  ╚═╝    ╚══════╝╚══════╝╚══════╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝ ╚═════╝
//                                                                                                 
//=======================================================================================================