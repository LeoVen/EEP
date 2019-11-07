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

$(document).ready(function () {
    if (typeof M === 'undefined') {
        alert('Error, Materialize library not loaded');
        return;
    }

    $('.modal').modal();
    $('select').formSelect();

    $('#loginSubmit').on('click', (event) => validateLogin(event));
    $('#signupSubmit').on('click', (event) => validateSignup(event));
    $('#logoutSubmitFake').on('click', () => $('#logoutSubmit').click());

    $('#createLanguageSubmit').on('click', (event) => validateCreateLang(event));
    $('#editLanguageSubmit').on('click', (event) => validateEditLang(event));
    $('#selectLanguageSubmit').on('click', (event) => validateSelectLanguage(event));
    $('#createWordSubmit').on('click', (event) => validateCreateWord(event));
    $('#editWordSubmit').on('click', (event) => validateEditWord(event));
    $('#selectTranslationSubmit').on('click', (event) => validateSelectTranslation(event));
    $('#createTranslationSubmit').on('click', (event) => validateCreateTranslation(event));

    $('.listingText').each(function () {
        let text = $(this).text();
        if (text.length > 40) {
            $(this).text(text.slice(0, 30) + '...');
        }
    });

    /* index.jsp */
    resetFieldsIndex();

    /* translation.jsp */
    $('#createTranslationWord1').attr('readonly', 'readonly');
    $('#createTranslationWord2').attr('readonly', 'readonly');

    if (typeof langId1 !== 'undefined' && typeof langId2 !== 'undefined') {
        $('#createTranslationLanguageId1').val(langId1);
        $('#createTranslationLanguageId2').val(langId2);
    }
});

/* -----------------------------------------------------------------------------
 * User
 ---------------------------------------------------------------------------- */
function resetFieldsIndex() {
    $('#loginUserName').val("");
    $('#loginUserPassword').val("");
    $('#signupUserName').val("");
    $('#signupUserPassword').val("");
}

function validateLogin(event) {
    let user = $('#loginUserName').val();
    let pass = $('#loginUserPassword').val();

    if (user === "" || pass === "" || user.length > 100 || pass.length > 100) {
        M.toast({html: 'User and Password must not be empty and must be less than 100 characters'});
        event.preventDefault();
        event.stopPropagation();
    }
}

function validateSignup(event) {
    let user = $('#signupUserName').val();
    let pass = $('#signupUserPassword').val();

    if (user === "" || pass === "" || user.length > 100 || pass.length > 100) {
        M.toast({html: 'User and Password must not be empty and must be less than 100 characters'});
        event.preventDefault();
        event.stopPropagation();
    }
}

/* -----------------------------------------------------------------------------
 * Language
 ---------------------------------------------------------------------------- */
function createLangModal() {
    $('#createLanguageError').text('');
    $('#createLanguageName').val('');
    $('#createLanguageName').attr('placeholder', 'Language Name');
    $('#createLanguageModal').modal('open');
}

function editLangModal(id, name) {
    $('#editLanguageError').text('');
    $('#editLanguageName').val(name);
    $('#editLanguageName').attr('placeholder', 'Language Name');
    $('#editLanguageName').focus();
    $('#editLanguageId').val(id);
    $('#editLanguageId').attr('readonly', 'readonly');
    $('#editLanguageModal').modal('open');
}

function deleteLangModal(id, name) {
    $('#deleteLanguageName').val(name);
    $('#deleteLanguageName').attr('readonly', 'readonly');
    $('#deleteLanguageId').val(id);
    $('#deleteLanguageId').attr('readonly', 'readonly');
    $('#deleteLanguageModal').modal('open');
}

function validateCreateLang(event) {
    let createLangValue = $('#createLanguageName').val();
    if (createLangValue === "" || createLangValue.length > 100) {
        M.toast({html: 'Language Name must not be empty and must be less than 100 characters'});
        event.preventDefault();
        event.stopPropagation();
    }
}

function validateEditLang(event) {
    let createLangValue = $('#editLanguageName').val();
    if (createLangValue === "" || createLangValue.length > 100) {
        M.toast({html: 'Language Name must not be empty and must be less than 100 characters'});
        event.preventDefault();
        event.stopPropagation();
    }
}

/* Select Language */
function selectLanguageModal() {
    $('#selectLanguageId').attr('readonly', 'readonly');
    $('#selectLanguageId').val(0);
    $('#selectLanguageName').attr('readonly', 'readonly');
    $('#selectLanguageName').val('');
    $('#selectLanguageModal').modal('open');
}

function selectLanguageSelection(id, languageName) {
    $('#selectLanguageId').attr('readonly', 'readonly');
    $('#selectLanguageId').val(id);
    $('#selectLanguageName').attr('readonly', 'readonly');
    $('#selectLanguageName').val(languageName);
}

function validateSelectLanguage(event) {
    let selectLanguageName = $('#selectLanguageName').val();
    if (selectLanguageName === "" || selectLanguageName.length > 100) {
        M.toast({html: 'Please select a valid language'});
        event.preventDefault();
        event.stopPropagation();
    }
}

/* -----------------------------------------------------------------------------
 * Word
 ---------------------------------------------------------------------------- */

function createWordModal(id, name) {
    $('#createWordLanguageId').val(id);
    $('#createWordLanguageId').attr('readonly', 'readonly');
    $('#createWordLanguageName').val(name);
    $('#createWordLanguageName').attr('readonly', 'readonly');
    $('#createWordWord').val('');
    $('#createWordWord').attr('placeholder', 'Word Text');
    $('#createWordModal').modal('open');
}

function editWordModal(langId, wordId, word) {
    $('#editWordWord').val(word);
    $('#editWordId').val(wordId);
    $('#editWordId').attr('readonly', 'readonly');
    $('#editWordLanguageId').val(langId);
    $('#editWordModal').modal('open');
}

function deleteWordModal(wordId, word) {
    $('#deleteWordWord').val(word);
    $('#deleteWordWord').attr('readonly', 'readonly');
    $('#deleteWordId').val(wordId);
    $('#deleteWordId').attr('readonly', 'readonly');
    $('#deleteWordModal').modal('open');
}

function validateCreateWord(event) {
    let createWordValue = $('#createWordWord').val();
    if (createWordValue === "" || createWordValue.length > 200) {
        M.toast({html: 'Word must not be empty and must be less than 200 characters'});
        event.preventDefault();
        event.stopPropagation();
    }
}

function validateEditWord(event) {
    let editWordWord = $('#editWordWord').val();
    if (editWordWord === "" || editWordWord.length > 100) {
        M.toast({html: 'Word must not be empty and must be less than 200 characters'});
        event.preventDefault();
        event.stopPropagation();
    }
}

/* -----------------------------------------------------------------------------
 * Translation
 ---------------------------------------------------------------------------- */
function selectWordForTranslation(part, id, word) {
    if (part === 1) {
        $('#createTranslationWordId1').val(id);
        $('#createTranslationWord1').val(word);
    } else if (part === 2) {
        $('#createTranslationWordId2').val(id);
        $('#createTranslationWord2').val(word);
    } else {
        M.toast({html: 'Front-end error: unknown ' + part});
    }
}

function validateCreateTranslation(event) {
    if (typeof langId1 === 'undefined' && typeof langId2 === 'undefined') {
        M.toast({html: 'Server Error: languages ID were not brought up to front-end'});
        return;
    }

    let word1 = $('#createTranslationWord1').val();
    let word2 = $('#createTranslationWord2').val();

    if (word1 === undefined || word1 === '' || word2 === undefined || word2 === '') {
        M.toast({html: 'Please select a valid word'});
        event.preventDefault();
        event.stopPropagation();
    } else {
        M.toast({html: 'Translation Created'});
        $('#createTranslationWord1').val('');
        $('#createTranslationWord2').val('');
    }
}

/* Select Translation */
var selectLangStep = 0;
function selectTranslationModal() {
    selectLangStep = 0;
    $('#selectLanguageName1').val('');
    $('#selectLanguageName1').addClass('border-selection');
    $('#selectLanguageName1').attr('readonly', 'readonly');
    $('#selectLanguageName2').val('');
    $('#selectLanguageName2').attr('readonly', 'readonly');
    $('#selectLanguageName2').removeClass('border-selection');
    $('#selectTranslationModal').modal('open');
}

function selectTranslationSelection(id, name) {
    /* Make a loop */
    if (selectLangStep === 0) {
        $('#selectLanguageId1').val(id);
        $('#selectLanguageName1').val(name);
        $('#selectLanguageName1').toggleClass('border-selection');
        $('#selectLanguageName2').toggleClass('border-selection');
        selectLangStep = 1;
    } else if (selectLangStep === 1) {
        $('#selectLanguageId2').val(id);
        $('#selectLanguageName2').val(name);
        $('#selectLanguageName1').toggleClass('border-selection');
        $('#selectLanguageName2').toggleClass('border-selection');
        selectLangStep = 0;
    } else {
        M.toast({html: 'Something went wrong. Please refresh the page.'});
    }
}

function validateSelectTranslation(event) {
    let selectLang1 = $('#selectLanguageName1').val();
    let selectLang2 = $('#selectLanguageName2').val();

    if (selectLang1 === "" || selectLang2 === "" || selectLang1.length > 100 || selectLang2.length > 100) {
        M.toast({html: 'Please select two valid languages'});
        event.preventDefault();
        event.stopPropagation();
    } else if (selectLang1 === selectLang2) {
        M.toast({html: 'Please select two different languages'});
        event.preventDefault();
        event.stopPropagation();
    }
}

/* -----------------------------------------------------------------------------
 * Dictionary
 ---------------------------------------------------------------------------- */
function deleteTranslationSelection(id) {
    $('#deleteTranslationId').val(id);
    $('#deleteTranslationSubmit').click();
}
