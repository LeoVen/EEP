package eep.as.leoven.util;

import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Formatter;


public class PasswordEncryption {

    // Encrypt String password to another Hexadecimal String
    public static String getSHA1(String password) {

        try {
            MessageDigest crypt = MessageDigest.getInstance("SHA-1");
            crypt.reset();
            crypt.update(password.getBytes("UTF-8"));
            return byteToHex(crypt.digest());
        } catch (NoSuchAlgorithmException e) {
            System.out.println("Algorithm SHA1 not found");
        } catch (UnsupportedEncodingException e) {
            System.out.println("Unsupported UTF-8 encoding");
        }

        return null;
    }

    // Formatts array of bytes to String of Hexadecimal
    private static String byteToHex(final byte[] hash) {

        Formatter formatter = new Formatter();

        for (byte b : hash) {
            formatter.format("%02x", b);
        }

        String result = formatter.toString();
        formatter.close();

        return result;
    }
}
