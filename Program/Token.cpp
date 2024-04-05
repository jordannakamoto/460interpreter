#include "Token.h"

// Constructors
// Note: Default constructor defined inline
Token::Token() {
    _eof = false;
}

// Initialize with Token_Type
Token::Token(Token_Type type) {
    set_TokenType(type);
}

Token::Token(std::string value, Token_Type type, int n) {
    set_TokenType(type);
    set_TokenValue(value);
    set_TokenLineNumber(n);
}

// Getters
std::string Token::getTokenValue() {
    return tokenValue;
}

Token_Type Token::getTokenType() {
    return tokenType;
}

std::string Token::getTokenTypeString(){
    return tokenTypeToString(tokenType);
}
int Token::getTokenLineNumber() {
    return lineNumber;
}

// Setters
void Token::set_TokenValue(std::string s) {
    tokenValue = s;
}

void Token::set_TokenType(Token_Type type) {
    tokenType = type;
}

void Token::set_TokenLineNumber(int n) {
    lineNumber = n;
}

// Function to convert Token_Type enum to string
// Some Types are printed as different from their enum entry.
std::string Token::tokenTypeToString(Token_Type type) {
    switch (type) {
        case Token_Type::NONE: return "NONE";
        case Token_Type::IDENTIFIER: return "IDENTIFIER";
        case Token_Type::LETTER: return "LETTER";
        case Token_Type::LETTER_UNDERSCORE: return "LETTER_UNDERSCORE";
        case Token_Type::LETTER_DIGIT: return "LETTER_DIGIT";
        case Token_Type::STRING: return "STRING";
        case Token_Type::CHARACTER: return "CHARACTER";
        case Token_Type::SINGLE_QUOTE: return "SINGLE_QUOTE";
        case Token_Type::DOUBLE_QUOTE: return "DOUBLE_QUOTE";
        case Token_Type::DIGIT: return "DIGIT";
        case Token_Type::PLUS: return "PLUS";
        case Token_Type::MINUS: return "MINUS";
        case Token_Type::ASTERISK: return "ASTERISK";
        case Token_Type::DIVIDE: return "DIVIDE";
        case Token_Type::MODULO: return "MODULO";
        case Token_Type::CARET: return "CARET";
        case Token_Type::LT: return "LESS_THAN";
        case Token_Type::GT: return "GREATER_THAN";
        case Token_Type::LT_EQUAL: return "LESS_THAN_OR_EQUAL";
        case Token_Type::GT_EQUAL: return "GREATER_THAN_OR_EQUAL";
        case Token_Type::BOOLEAN_AND: return "BOOLEAN_AND";
        case Token_Type::BOOLEAN_OR: return "BOOLEAN_OR";
        case Token_Type::BOOLEAN_NOT: return "BOOLEAN_NOT";
        //case Token_Type::BOOLEAN_EQUAL: return "BOOLEAN_EQUAL";
        case Token_Type::BOOLEAN_EQUAL: return "EQUAL";
        case Token_Type::BOOLEAN_NOT_EQUAL: return "BOOLEAN_NOT_EQUAL";
        case Token_Type::WHOLE_NUMBER: return "WHOLE_NUMBER";
        case Token_Type::INTEGER: return "INTEGER";
        //case Token_Type::ASSIGNMENT_OPERATOR: return "ASSIGNMENT_OPERATOR";
        case Token_Type::ASSIGNMENT_OPERATOR: return "ASSIGNMENT";
        case Token_Type::LEFT_PARENTHESIS: return "LEFT_PARENTHESIS";
        case Token_Type::RIGHT_PARENTHESIS: return "RIGHT_PARENTHESIS";
        case Token_Type::LEFT_BRACE: return "LEFT_BRACE";
        case Token_Type::RIGHT_BRACE: return "RIGHT_BRACE";
        case Token_Type::LEFT_BRACKET: return "LEFT_BRACKET";
        case Token_Type::RIGHT_BRACKET: return "RIGHT_BRACKET";
        case Token_Type::SEMICOLON: return "SEMICOLON";
        case Token_Type::COMMA: return "COMMA";
        case Token_Type::ESCAPE_CHARACTER: return "ESCAPED_CHARACTER"; // Discrepancy
        default: return "UNKNOWN";
    }
}
bool &Token::endOfFile() { return _eof; }
