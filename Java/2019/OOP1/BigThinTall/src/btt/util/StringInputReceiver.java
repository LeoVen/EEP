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
public class StringInputReceiver {

    public String message;
    public boolean cancelled;

    public StringInputReceiver() {
        message = null;
        cancelled = true;
    }
}
