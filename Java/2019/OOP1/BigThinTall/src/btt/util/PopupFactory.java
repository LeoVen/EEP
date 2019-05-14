/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.util;

/**
 *
 * @author lvenk
 */
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
