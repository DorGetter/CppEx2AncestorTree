//
// Created by Dor Getter on 15/04/2020.
//
#define CHECK DOCTEST_CHECK

#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace family;



TEST_CASE("Initializing Tree Of The British Royal Family") {



/////////////////////////////////////////////////////////
/////////////Prince Louis Tree//////////////////////////
///////////////////////////////////////////////////////

    family::Tree T("Prince Louis"); // Louis is the "root" of the tree (the youngest person).
    T.addFather("Prince Louis", "Prince Williams")   // Tells the tree that the father of Louis is Williams.
            .addMother("Prince Louis", "Kate Middleton");  // Tells the tree that the mother of Louis is Kate.

    T.addFather("Prince Williams", "Prince Charles");
    T.addMother("Prince Williams", "Princess Diana");

    T.addFather("Kate Middleton", "Micheal Middleton");
    T.addMother("Kate Middleton", "Carole Middleton");


    T.addFather("Prince Charles", "King philip");
    T.addMother("Prince Charles", "Queen Elizabeth 2");

    T.addFather("Princess Diana", "John Spencer");
    T.addMother("Princess Diana", "Frances Shand Kydd");

    T.addMother("Queen Elizabeth 2", "Queen Elizabeth");
    T.addFather("Queen Elizabeth 2", "King George 6");
    std::cout<< "\n\t\t///////////////////////////////////////\n\t\t//////   British Royal Family   //////\n\t\t/////////////////////////////////////\n" << std::endl; 
    T.display();

    /////////////////////////
    ////////Existence///////
    ///////////////////////
    CHECK(T.root);
    CHECK(T.root->Dad);
    CHECK(T.root->Mom);
    CHECK(T.root->Dad->Dad);
    CHECK(T.root->Dad->Mom);
    CHECK(T.root->Mom->Dad);
    CHECK(T.root->Mom->Mom);
    CHECK(T.root->Dad->Dad->Dad);
    CHECK(T.root->Dad->Dad->Mom);
    CHECK(T.root->Dad->Mom->Dad);
    CHECK(T.root->Dad->Mom->Mom);
    CHECK(T.root->Dad->Dad->Mom->Mom);
    CHECK(T.root->Dad->Dad->Mom->Dad);

    /////////////////////////
    ////////Rightness///////
    ///////////////////////
    CHECK(T.root->name == "Prince Louis");
    CHECK(T.root->Dad->name == "Prince Williams");
    CHECK(T.root->Mom->name == "Kate Middleton");
    CHECK(T.root->Dad->Dad->name == "Prince Charles");
    CHECK(T.root->Dad->Mom->name == "Princess Diana");
    CHECK(T.root->Mom->Dad->name == "Micheal Middleton");
    CHECK(T.root->Mom->Mom->name == "Carole Middleton");
    CHECK(T.root->Dad->Dad->Dad->name == "King philip");
    CHECK(T.root->Dad->Dad->Mom->name == "Queen Elizabeth 2");
    CHECK(T.root->Dad->Mom->Dad->name == "John Spencer");
    CHECK(T.root->Dad->Mom->Mom->name == "Frances Shand Kydd");
    CHECK(T.root->Dad->Dad->Mom->Mom->name == "Queen Elizabeth");
    CHECK(T.root->Dad->Dad->Mom->Dad->name == "King George 6");

    /////////////////////////
    ////////relations///////
    ///////////////////////
    CHECK(T.relation("Prince Louis")=="Me");
    CHECK(T.relation("Prince Williams")=="father");
    CHECK(T.relation("Kate Middleton")=="mother");
    CHECK(T.relation("Prince Charles")=="grandfather");
    CHECK(T.relation("Princess Diana")=="grandmother");
    CHECK(T.relation("Micheal Middleton")=="grandfather");
    CHECK(T.relation("Carole Middleton")=="grandmother");
    CHECK(T.relation("King philip")=="great-grandfather");
    CHECK(T.relation("Queen Elizabeth 2")=="great-grandmother");
    CHECK(T.relation("John Spencer")=="great-grandfather");
    CHECK(T.relation("Frances Shand Kydd")=="great-grandmother");
    CHECK(T.relation("Queen Elizabeth")=="great-great-grandmother");
    CHECK(T.relation("King George 6")=="great-great-grandfather");

    CHECK(T.relation("Squirtel")=="unrelated");
    CHECK(T.relation("Charizard")=="unrelated");
    CHECK(T.relation("John Smith")=="unrelated");
    CHECK(T.relation("captain Jack Sparrow")=="unrelated");

    /////////////////////////
    /////////find///////////
    ///////////////////////
    CHECK(T.find("Me")=="Prince Louis");
    CHECK(T.find("father")=="Prince Williams");
    CHECK(T.find("mother")=="Kate Middleton");
    CHECK(T.find("grandfather")=="Prince CharlesMicheal Middleton");
    CHECK(T.find("grandmother")=="Princess DianaCarole Middleton");
    CHECK(T.find("great-grandfather")=="King philipJohn Spencer");
    CHECK(T.find("great-grandmother")=="Queen Elizabeth 2Frances Shand Kydd");
    CHECK(T.find("great-great-grandfather")=="King George 6");
    CHECK(T.find("great-great-grandmother")=="Queen Elizabeth");

    /////////////////////////
    ////Throw exception/////
    ///////////////////////
    CHECK_THROWS(T.find("daddy"));
    CHECK_THROWS(T.find("mommy"));
    CHECK_THROWS(T.find("uncle"));
    CHECK_THROWS(T.find("brother"));
    CHECK_THROWS(T.find("sister"));
    CHECK_THROWS(T.find("nephew"));
    CHECK_THROWS(T.find("sibling"));

    ///////////////////////////
    /////Remove From Tree/////
    /////////////////////////

    T.remove("Prince Charles");
    CHECK(T.relation("Queen Elizabeth")=="unrelated");
    CHECK(T.relation("King George 6")=="unrelated");
    CHECK(T.relation("King philip")=="unrelated");
    CHECK(T.relation("Queen Elizabet 2")=="unrelated");
    CHECK(T.relation("Prince Charles")=="unrelated");
    CHECK(T.relation("Prince Williams")=="father");

    //////////////////////////////////////////////////////////////////////////////
    ////////////////////////////New Tree- LION KING//////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
  
      std::cout<< "\n\t\t///////////////////////////////////////\n\t\t////////   Lion King Family   ////////\n\t\t/////////////////////////////////////\n" << std::endl; 
   
    family::Tree L("Kiara");
     L.addFather("Kiara", "Simba")   // Tells the tree that the father of Louis is Williams.
            .addMother("Kiara", "Nala");  // Tells the tree that the mother of Louis is Kate.

    L.addFather("Simba", "Mufasa");
    L.addMother("Simba", "Sarabi");

    L.addFather("Nala", "Unknown");
    L.addMother("Nala", "Sarafina");

    L.addFather("Mufasa", "Ahadi");
    L.addMother("Mufasa", "Ura");

    L.addFather("Ahadi", "Mohatu");
    L.addMother("Ahadi", "Unknown2");


    L.display();

    /////////////////////////
    ////////Existence///////
    ///////////////////////
    CHECK(L.root);
    CHECK(L.root->Dad);
    CHECK(L.root->Mom);
    CHECK(L.root->Dad->Dad);
    CHECK(L.root->Dad->Mom);
    CHECK(L.root->Mom->Dad);
    CHECK(L.root->Mom->Mom);
    CHECK(L.root->Dad->Dad->Dad);
    CHECK(L.root->Dad->Dad->Mom);



    /////////////////////////
    ////////Rightness///////
    ///////////////////////
    CHECK(L.root->name == "Kiara");
    CHECK(L.root->Dad->name == "Simba");
    CHECK(L.root->Mom->name == "Nala");
    CHECK(L.root->Dad->Dad->name == "Mufasa");
    CHECK(L.root->Dad->Mom->name == "Sarabi");
    CHECK(L.root->Mom->Dad->name == "Unknown");
    CHECK(L.root->Mom->Mom->name == "Sarafina");
    CHECK(L.root->Dad->Dad->Dad->name == "Ahadi");
    CHECK(L.root->Dad->Dad->Mom->name == "Ura");

    CHECK(L.root->Dad->Dad->Dad->Mom->name == "Unknown2");
    CHECK(L.root->Dad->Dad->Dad->Dad->name == "Mohatu");

    /////////////////////////
    ////////relations///////
    ///////////////////////
    CHECK(L.relation("Kiara")=="Me");
    CHECK(L.relation("Simba")=="father");
    CHECK(L.relation("Nala")=="mother");
    CHECK(L.relation("Mufasa")=="grandfather");
    CHECK(L.relation("Sarabi")=="grandmother");
    CHECK(L.relation("Sarafina")=="grandmother");
    CHECK(L.relation("Unknown")=="grandfather");
    CHECK(L.relation("Ahadi")=="great-grandfather");
    CHECK(L.relation("Ura")=="great-grandmother");
    CHECK(L.relation("Mohatu")=="great-great-grandfather");
    CHECK(L.relation("Unknown2")=="great-great-grandmother");

    CHECK(L.relation("Scar")=="unrelated");
    CHECK(L.relation("Zira")=="unrelated");
    CHECK(L.relation("Kova")=="unrelated");


    /////////////////////////
    ////Throw exception/////
    ///////////////////////
    CHECK_THROWS(L.find("daddy"));
    CHECK_THROWS(L.find("mommy"));
    CHECK_THROWS(L.find("uncle"));
    CHECK_THROWS(L.find("brother"));
    CHECK_THROWS(L.find("sister"));
    CHECK_THROWS(L.find("nephew"));
    CHECK_THROWS(L.find("KITTEN"));

    /////////////////////////
    /////////find///////////
    ///////////////////////

    CHECK(L.find("Me")=="Kiara");
    CHECK(L.find("father")=="Simba");
    CHECK(L.find("mother")=="Nala");
    CHECK(L.find("grandfather")=="MufasaUnknown");
    CHECK(L.find("grandmother")=="SarabiSarafina");
    CHECK(L.find("great-grandfather")=="Ahadi");
    CHECK(L.find("great-grandmother")=="Ura");
    CHECK(L.find("great-great-grandfather")=="Mohatu");
    CHECK(L.find("great-great-grandmother")=="Unknown2");


    //////////////////////////
    /////Remove From Tree/////
    /////////////////////////

    L.remove("Mufasa");
    CHECK(T.relation("Mufasa")=="unrelated");
    CHECK(T.relation("Ahadi")=="unrelated");
    CHECK(T.relation("Ura")=="unrelated");
    CHECK(T.relation("Mohatu")=="unrelated");
    CHECK(T.relation("Unknown2")=="unrelated");
}



