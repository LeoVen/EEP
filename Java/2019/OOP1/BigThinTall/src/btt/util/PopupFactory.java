package btt.util;

import btt.screens.ErrorMessage;
import btt.screens.SuccessMessage;


public class PopupFactory {
    
    public static void showError(java.awt.Frame parent, String errorMessage) {
        ErrorMessage err = new ErrorMessage(parent, true, "<html> " + errorMessage);
        err.setVisible(true);
    }

    public static void showSuccess(java.awt.Frame parent, String successMessage) {
        SuccessMessage msg = new SuccessMessage(parent, true, "<html> " + successMessage);
        msg.setVisible(true);
    }
}
