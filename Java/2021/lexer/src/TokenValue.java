public class TokenValue {
    private long integer;
    private double realNumber;
    private String string;

    private TokenValueType ttype;

    public enum TokenValueType {
        INTEGER,
        REAL,
        STRING,
    }

    public TokenValue(long value) {
        this.integer = value;
        this.ttype = TokenValueType.INTEGER;
    }

    public TokenValue(double value) {
        this.realNumber = value;
        this.ttype = TokenValueType.REAL;
    }

    public TokenValue(String value) {
        this.string = value;
        this.ttype = TokenValueType.STRING;
    }

    public TokenValueType resultType() {
        return this.ttype;
    }

    public long getInteger() throws IllegalAccessException {
        if (this.ttype != TokenValueType.INTEGER)
            throw new IllegalAccessException("Result type is not integer");

        return integer;
    }

    public double getRealNumber() throws IllegalAccessException {
        if (this.ttype != TokenValueType.REAL)
            throw new IllegalAccessException("Result type is not real value");

        return realNumber;
    }

    public String getString() throws IllegalAccessException {
        if (this.ttype != TokenValueType.STRING)
            throw new IllegalAccessException("Result type is not string");

        return string;
    }

    @Override
    public String toString() {
        Object value = null;
        switch (ttype) {
            case INTEGER -> value = this.integer;
            case REAL -> value = this.realNumber;
            case STRING -> value = this.string;
        }

        return value.toString();
    }
}
