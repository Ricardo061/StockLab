/* =======================================================================================================
 *
 * Arquivo Classe para Users .hpp
 * Classe Login e Senha.
 * Author: Joao Ricardo Chaves
 * Date: 30/05/25
 * 
 * =======================================================================================================
 */ 

// ============================================
// --- Pre-processing directives ---

#ifndef USERS_HPP
#define USERS_HPP 

// ============================================
// --- Libraries ---
#include "includes.hpp"

// ============================================
// --- Class ---

class Users
{
    public:
        Users();

        void SetLogin(const string &Login);
        string getLogin() const;

        void SetPassword(const string &Password);
        unsigned long getPassword() const;

        bool autentic(const string &Login, const string &Password);
        void RegisterUser() const;
    private:
        string _Login;
        unsigned long _Password;

        unsigned long generateHash(const string &str) const;
        bool LoadUsers(const string &Login, const string &Password);
        string usersFile = string(DATA_PATH) + "users.txt";
}; // end class





#endif
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