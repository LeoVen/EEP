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
    // the "href" attribute of the modal trigger must specify the modal ID that wants to be triggered
    $('.modal').modal();
    $('select').material_select();
    $('#createLanguageName').attr('placeholder', 'Language Name');

    $('#createLanguageSubmit').on('click', (event) => validateCreateLang(event));
    $('#editLanguageSubmit').on('click', (event) => validateEditLang(event));
    $('#selectLanguageSubmit').on('click', (event) => validateSelectLanguage(event));
    $('#createWordSubmit').on('click', (event) => validateCreateWord(event));
    $('#editWordSubmit').on('click', (event) => validateEditWord(event));
    $('#selectTranslationSubmit').on('click', (event) => selectTranslationSubmit(event));

    $('.listingText').each(function () {
        let text = $(this).text();
        if (text.length > 40) {
            $(this).text(text.slice(0, 30) + '...');
        }
    });
});

/* -----------------------------------------------------------------------------
 * Language
 ---------------------------------------------------------------------------- */
function createLangModal() {
    $('#createLanguageError').text('');
    $('#createLanguageName').val('');
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
        Materialize.toast('Language Name must not be empty and must be less than 100 characters', 4000);
        event.preventDefault();
        event.stopPropagation();
    }
}

function validateEditLang(event) {
    let createLangValue = $('#editLanguageName').val();
    if (createLangValue === "" || createLangValue.length > 100) {
        Materialize.toast('Language Name must not be empty and must be less than 100 characters', 4000);
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
        Materialize.toast('Please select a valid language', 4000);
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
        Materialize.toast('Word must not be empty and must be less than 200 characters', 4000);
        event.preventDefault();
        event.stopPropagation();
    }
}

function validateEditWord(event) {
    let editWordWord = $('#editWordWord').val();
    if (editWordWord === "" || editWordWord.length > 100) {
        Materialize.toast('Word must not be empty and must be less than 200 characters', 4000);
        event.preventDefault();
        event.stopPropagation();
    }
}

/* -----------------------------------------------------------------------------
 * Translation
 ---------------------------------------------------------------------------- */

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
        Materialize.toast('Something went wrong. Please refresh the page.');
    }
}

function selectTranslationSubmit(event) {
    let selectLang1 = $('#selectLanguageName1').val();
    let selectLang2 = $('#selectLanguageName2').val();

    if (selectLang1 === "" || selectLang2 === "" || selectLang1.length > 100 || selectLang2.length > 100) {
        Materialize.toast('Please select two valid languages', 4000);
        event.preventDefault();
        event.stopPropagation();
    } else if (selectLang1 === selectLang2) {
        Materialize.toast('Please select two different languages', 4000);
        event.preventDefault();
        event.stopPropagation();
    }
}
