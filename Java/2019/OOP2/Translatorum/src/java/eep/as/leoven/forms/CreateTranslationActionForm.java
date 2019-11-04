/*
 * The MIT License
 *
 * Copyright 2019 Leonardo Vencovsky (https://github.com/LeoVen/).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package eep.as.leoven.forms;

import javax.servlet.http.HttpServletRequest;

import org.apache.struts.action.ActionErrors;
import org.apache.struts.action.ActionMapping;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class CreateTranslationActionForm extends org.apache.struts.action.ActionForm {

    private int wordId1;
    private String word1;
    private int languageId1;

    private int wordId2;
    private String word2;
    private int languageId2;

    /**
     *
     */
    public CreateTranslationActionForm() {
        super();
        // TODO Auto-generated constructor stub
    }

    /**
     * This is the action called from the Struts framework.
     *
     * @param mapping The ActionMapping used to select this instance.
     * @param request The HTTP Request we are processing.
     * @return
     */
    @Override
    public ActionErrors validate(ActionMapping mapping, HttpServletRequest request) {
        // Validation is done in the front-end
        return new ActionErrors();
    }

    public int getWordId1() {
        return wordId1;
    }

    public void setWordId1(int wordId1) {
        this.wordId1 = wordId1;
    }

    public String getWord1() {
        return word1;
    }

    public void setWord1(String word1) {
        this.word1 = word1;
    }

    public int getLanguageId1() {
        return languageId1;
    }

    public void setLanguageId1(int languageId1) {
        this.languageId1 = languageId1;
    }

    public int getWordId2() {
        return wordId2;
    }

    public void setWordId2(int wordId2) {
        this.wordId2 = wordId2;
    }

    public String getWord2() {
        return word2;
    }

    public void setWord2(String word2) {
        this.word2 = word2;
    }

    public int getLanguageId2() {
        return languageId2;
    }

    public void setLanguageId2(int languageId2) {
        this.languageId2 = languageId2;
    }

}
