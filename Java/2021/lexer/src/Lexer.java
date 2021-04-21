import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Lexer {
    private BufferedReader reader;
    private int currentChar;
    private String memory;
    private boolean finished = false;
    private boolean goNext = true;

    public Lexer(BufferedReader reader) {
        this.reader = reader;
        this.memory = "";
    }

    public List<Token<TokenType, TokenValue>> parse() throws IOException {
        ArrayList<Token<TokenType, TokenValue>> result = new ArrayList<>();

        while (!finished) {
            if (goNext)
                this.nextChar();
            else
                goNext = true;
            this.seek();
            Token<TokenType, TokenValue> token = nextToken();
            if (token != null) {
                result.add(token);
            }
        }

        return result;
    }

    private void nextChar() throws IOException {
        currentChar = reader.read();
    }

    public void seek() throws IOException {
        while (Character.isSpaceChar(currentChar)) {
            this.nextChar();
        }
    }

    public Token<TokenType, TokenValue> nextToken() throws IOException {
        if (Character.isDigit(currentChar)) {
            return getNumber();
        } else if (Character.isAlphabetic(currentChar)) {
            return getIdentifier();
        }  else if (currentChar != -1) {
            return getOperator();
        }

        // EOF
        finished = true;
        return null;
    }

    private Token<TokenType, TokenValue> getIdentifier() throws IOException {
        StringBuilder readResult = new StringBuilder();

        while (Character.isAlphabetic(currentChar)) {
            readResult.append((char)currentChar);
            nextChar();
        }

        return new Token<>(TokenType.IDENT, new TokenValue(readResult.toString()));
    }

    private Token<TokenType, TokenValue> getOperator() throws IOException {
        if (!memory.isEmpty()) {
            switch (memory.charAt(0)) {
                case '<' -> {
                    memory = "";
                    return new Token<>(TokenType.CMP_LT, new TokenValue("<"));
                }
                case '>' -> {
                    memory = "";
                    return new Token<>(TokenType.CMP_GT, new TokenValue(">"));
                }
            }
        }

        switch (currentChar) {
            case '+' -> {
                return new Token<>(TokenType.OP_ADD, new TokenValue("+"));
            }
            case '-' -> {
                return new Token<>(TokenType.OP_NEG, new TokenValue("-"));
            }
            case '*' -> {
                return new Token<>(TokenType.OP_MUL, new TokenValue("*"));
            }
            case '/' -> {
                return new Token<>(TokenType.OP_DIV, new TokenValue("/"));
            }
            case '~' -> {
                return new Token<>(TokenType.OP_NOT, new TokenValue("~"));
            }
            case '&' -> {
                return new Token<>(TokenType.OP_AND, new TokenValue("& "));
            }
            case '|' -> {
                return new Token<>(TokenType.OP_OR, new TokenValue("|"));
            }
            case '(' -> {
                return new Token<>(TokenType.PAREN_OPEN, new TokenValue("("));
            }
            case ')' -> {
                return new Token<>(TokenType.PAREN_CLOSE, new TokenValue(")"));
            }
            case '{' -> {
                return new Token<>(TokenType.BRACK_OPEN, new TokenValue("{"));
            }
            case '}' -> {
                return new Token<>(TokenType.BRACK_CLOSE, new TokenValue("}"));
            }
            case '<' -> {
                nextChar();
                switch (currentChar) {
                    case '=' -> {
                        return new Token<>(TokenType.CMP_LE, new TokenValue("<="));
                    }
                    default -> {
                        addToMemory("<");
                        return getOperator();
                    }
                }
            }
            case '>' -> {
                nextChar();
                switch (currentChar) {
                    case '=' -> {
                        return new Token<>(TokenType.CMP_GE, new TokenValue(">="));
                    }
                    default -> {
                        addToMemory(">");
                        return getOperator();
                    }
                }
            }
            case '=' -> {
                nextChar();
                switch (currentChar) {
                    case '=' -> {
                        return new Token<>(TokenType.CMP_EQ, new TokenValue("=="));
                    }
                    default -> {
                        addToMemory("=");
                        return getOperator();
                    }
                }
            }
        }

        return null;
    }

    private void addToMemory(String s) {
        memory += s;
    }

    private Token<TokenType, TokenValue> getNumber() throws IOException {
        StringBuilder readResult = new StringBuilder();

        while (Character.isDigit(currentChar)) {
            readResult.append((char)currentChar);
            nextChar();
        }

        if (currentChar == '.') {
            readResult.append((char)currentChar);
            nextChar();
            while (Character.isDigit(currentChar)) {
                readResult.append((char)currentChar);
                nextChar();
            }

            goNext = false;
            return new Token<>(TokenType.NUMBER, new TokenValue(Double.parseDouble(readResult.toString())));
        }

        goNext = false;
        return new Token<>(TokenType.NUMBER, new TokenValue(Integer.parseInt(readResult.toString())));
    }
}
