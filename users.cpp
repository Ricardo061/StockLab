/* =======================================================================================================
 *
 * Arquivo Users .cpp
 * Classe para Login e Senha.
 * Author: Joao Ricardo Chaves
 * Date: 30/05/25
 * 
 * =======================================================================================================
 */ 

// ============================================
// --- Libraries ---
#include "users.hpp"

// ============================================
// --- Functions ---

// ============================================ 
// --- Constructor ---
Users::Users()
{

}// end constructor

// ============================================
// --- SetLogin ---
void Users::SetLogin(const string &Login)
{
    _Login = Login;
}// end SetLogin

// ============================================
// --- getLogin ---
string Users::getLogin() const
{
    return _Login;
}// end getLogin

// ============================================
// --- SetPassword ---
void Users::SetPassword(const string &Password)
{
    _Password = generateHash(Password);
}// end SetPassword

// ============================================
// --- getPassword ---
unsigned long Users::getPassword() const
{
    return _Password;
}// end getPassword

// ============================================
// --- Autentic ---
bool Users::autentic(const string &Login, const string &Password)
{
    return LoadUsers(Login,Password);
}// end Autentic 

// ============================================
// --- RegisterUser ---
void Users::RegisterUser() const
{

    ifstream UsersRead("usersFile", ios::in);
    if (UsersRead)
    {
        string line;
        while (getline(UsersRead, line))
        {
            size_t pos = line.find(',');
            if (pos != string::npos)
            {
                string loginRead = line.substr(0, pos);
                if (loginRead == getLogin())
                {
                    cout << RED << "\nErro: Usuário já cadastrado!\n";
                    UsersRead.close();
                    return;
                }// end if aninhado
            }//end if
        }//end while
        UsersRead.close();
    }// end if

    // Se não existe, cadastra
    ofstream UsersArq("usersFile", ios::app);
    if (!UsersArq)
    {
        cerr << RED << "Falha na criação do arquivo!" << endl;
        return;
    }//end if

    UsersArq << getLogin() << "," << getPassword() << "\n";
    UsersArq.close();

    cout << GREEN << "\nUsuário cadastrado com sucesso!\n";
}// end RegisterUser

// ============================================
// --- LoadUsers ---
bool Users::LoadUsers(const string &Login, const string &Password)
{
    ifstream UsersRead("usersFile",ios::in);
    if(!UsersRead)
    { 
        cerr << RED << "Falha na leitura de arquivo!" << endl;
        return false;
    }// end if

    string line;
    while(getline(UsersRead,line))
    {
        size_t pos = line.find(',');  // pos encontra o indice que esta a ',' se nao for encontrada retorna string::npos
        if(pos != string::npos)
        {
            string loginRead = line.substr(0,pos);       //pega a substring e vai de 0 ate pos-1 ou seja o user
            string PassWordstr = line.substr(pos+1);     // pega a substring e vai de pos+1 ate o fim, ou seja pula a ',' e pega a senha.

            unsigned long PasswordRead = stoul(PassWordstr);  // converte de string para unsigned long
            if(loginRead == Login && PasswordRead == generateHash(Password))
            {
                _Login = loginRead;
                _Password = PasswordRead;
                UsersRead.close();
                return true;
            }// end if aninhado
        }// end if
    }//end while
    UsersRead.close();
    return false;
}// end Loadusers

// ============================================
// --- GenerateHash ---
unsigned long Users::generateHash(const string &str) const
{
    unsigned long hash = 5381;
    for(char c : str)
        hash = ((hash << 5) + hash) + c;
    return hash;
}// end GenerateHash







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