// ****************************************************************
// * Assignment 3: Recursive Decent Parser                        *
// * Nick Cabrales, Brayan Vizcaino, Jordan Nakamoto, Jacob Jaffe *
// * main.cpp                                                     *
// ****************************************************************

#include "FileHandler.h"
#include "CommentRemover.h"
#include "Tokenizer.h"
#include "TokenList.h"
#include "ErrorHandler.h"
#include "SymbolTable.h"
#include "ConcreteSyntaxTree.h"
#include "RecursiveDescentParser.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Check if the correct number of program arguments is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        exit(1);
    }

    FileHandler fileHandler;
    ErrorHandler& eh = ErrorHandler::get(); // error handler reference
    eh.fileName = fileHandler.getFileName();  // pass fileName to error handler, so it can produce error outFiles

    /* P1: Procedure for opening a code file, removing comments, & storing result -------- */
    fileHandler.openFile(argv[1]);
    CommentRemover commentRemover(fileHandler.fileStream);
    
    commentRemover.processFile();                  // Remove Comments, store in result
    // commentRemover.printCommentRemovedFile();
    fileHandler.outputWithoutCommentsToFile(commentRemover);
    /* END P1 =========================================================================== */

    /* P2: Procedure for tokenizing and outputting to file ------------------------------- */
    //std::cout << "Tokenizing" << std::endl;
    Tokenizer tokenizer(commentRemover.result);
    TokenList* tokenLinkedList;

    tokenLinkedList = tokenizer.TokenizeToLinkedList();
    // tokenLinkedList->printList();
    fileHandler.outputTokenListToFile(tokenLinkedList);
    /* END P2 =========================================================================== */

    /* P3: Procedure for creating a concrete syntax tree using recursive descent parsing-- */
    //std::cout << "Recursive Descent" << std::endl;
    RecursiveDescentParser recursiveDescentParser(tokenLinkedList);
    ConcreteSyntaxTree* concreteSyntaxTree;

    concreteSyntaxTree = recursiveDescentParser.LinkedListToCST();
    // concreteSyntaxTree.printList();
    // concreteSyntaxTree.printInstructions();
    fileHandler.outputCSTToFile(concreteSyntaxTree); 
    /* END P3 ============================================================================ */

    /* P4: Procedure for generating a valid symbol table --------------------------------- */
    //std::cout << "Parsing Symbol Table" << std::endl;
    SymbolTable* st = new SymbolTable();
    
    st->createSymbolTable(concreteSyntaxTree);
    // st->printTable();
    fileHandler.outputSymbolTableToFile(st);
    /* END P4 ============================================================================ */

    /* P5: Generating Abstract Syntax Tree ----------------------------------------------- */





    /* END P5 ============================================================================  */
    // Cleanup
    // I think because all the Tokens are shared by TLL, CST, and ST
    // We only need to delete the TLL... but individual Node structs for each will live on?
    delete concreteSyntaxTree;  // from P3  

    return 0;
}
