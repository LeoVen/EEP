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
package eep.as.leoven.controller;

import eep.as.leoven.vo.Language;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class PageContentController {

    static public boolean noCaching = true;

    static Language currentLanguage = null;

    static Language translationLanguage1 = null;

    static Language translationLanguage2 = null;

    public static Language getCurrentLanguage() {
        return currentLanguage;
    }

    public static void setCurrentLanguage(Language currentLanguage) {
        PageContentController.currentLanguage = new Language(
                currentLanguage.getId(),
                currentLanguage.getName(),
                currentLanguage.getWords());
    }

    public static Language getTranslationLanguage1() {
        return translationLanguage1;
    }

    public static void setTranslationLanguage1(Language translationLanguage1) {
        PageContentController.translationLanguage1 = new Language(
                translationLanguage1.getId(),
                translationLanguage1.getName(),
                translationLanguage1.getWords());
    }

    public static Language getTranslationLanguage2() {
        return translationLanguage2;
    }

    public static void setTranslationLanguage2(Language translationLanguage2) {
        PageContentController.translationLanguage2 = new Language(
                translationLanguage2.getId(),
                translationLanguage2.getName(),
                translationLanguage2.getWords());
    }

}
