/* =======================================================================================================
 *
 * Arquivo Classe .hpp
 * Programa para controle de estoque.
 * Author: Joao Ricardo Chaves
 * Date: 30/05/25
 * 
 * =======================================================================================================
 */ 

// ============================================
// --- Pre-processing directives ---

#ifndef COMPONENT_HPP
#define COMPONENT_HPP 

// ============================================
// --- Libraries ---
#include "includes.hpp"

// ============================================
// --- Class ---

class Registercomp
{
    public:
        Registercomp();
        
        void SetID(int ID);
        int getID() const;

        void SetQuantidade(int QTD);
        int getQuantidade() const;

        void SetPrice(double Price);
        double getPrice() const;

        void SetName(const string &Name);
        string getName() const;

        void SetCategory(const string &Category);
        string getCategory() const;

        void SetValue(double Value);
        double getValue() const;

        void SetDescription(const string &Description);
        string getDescription() const;

        void RemoveProduct() const;
        void ModifyProduct() const;

        void RegisterComponent() const; 
        void LoadStock() const;
        void PrintCharline() const;

    private:
        int    _ID;        
        int    _Qtd;        
        double _Price;
        string _Name; 
        string _Category; 
        double _Value;
        string _description;

        string stockFile = string(DATA_PATH) + "stockregister.txt";
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