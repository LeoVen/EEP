<%-- 
    Document   : translation.jsp
    Created on : 31/10/2019, 20:09:49
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="java.util.List"%>
<%@page import="eep.as.leoven.controller.PageContentController"%>
<%@page import="eep.as.leoven.dao.WordDAO"%>
<%@page import="eep.as.leoven.vo.Word"%>
<%@page import="eep.as.leoven.vo.Language"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    // Prevent caching
    if (PageContentController.noCaching) {
        response.setDateHeader("Expires", 0);
    }

    Language lang1 = PageContentController.getTranslationLanguage1();
    Language lang2 = PageContentController.getTranslationLanguage2();

    WordDAO wordDao = new WordDAO();

    List<Word> words1 = wordDao.getByLanguage(lang1);
    List<Word> words2 = wordDao.getByLanguage(lang2);
%>

<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/css/materialize.min.css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="${pageContext.request.contextPath}/css/main.css" type="text/css" >
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Translatorum</title>
    </head>
    <body>
        <!-- FAB -->
        <div class="fixed-action-btn">
            <a href="index.jsp" class="btn-floating btn-large orange">
                <i class="larg material-icons">keyboard_return</i>
            </a>
        </div>

        <div class="big-card-parent">
            <div class="big-card-child card" style="margin: 0;">
                <div class="card-content" style="margin: 0; padding: 0;">
                    <h5 class="center-align">Add Translation</h5>
                    <div class="row">
                        <div class="col s6">
                            <span class="card-title center-align"><%= lang1.getName()%></span>
                            <div class="word-listing">
                                <ul class="collection">
                                    <% for (Word word : words1) {%>
                                    <a href="javascript:selectWordForTranslation(1, <%= word.getId()%>, '<%= word.getWord()%>')" class="collection-item">
                                        <span class="listingText"><%= word.getWord()%></span>
                                    </a>
                                    <% }%>
                                </ul>
                            </div>
                        </div>
                        <div class="col s6">
                            <span class="card-title center-align"><%= lang2.getName()%></span>
                            <div class="word-listing">
                                <ul class="collection">
                                    <% for (Word word : words2) {%>
                                    <a href="javascript:selectWordForTranslation(2, <%= word.getId()%>, '<%= word.getWord()%>')" class="collection-item">
                                        <span class="listingText"><%= word.getWord()%></span>
                                    </a>
                                    <% }%>
                                </ul>
                            </div>
                        </div>
                    </div>
                    <html:form action="CreateTranslation">
                        <div class="display-none">
                            <html:text styleId="createTranslationLanguageId1" name="CreateTranslationActionForm" property="languageId1"/>
                            <html:text styleId="createTranslationLanguageId2" name="CreateTranslationActionForm" property="languageId2"/>
                            <html:text styleId="createTranslationWordId1" name="CreateTranslationActionForm" property="wordId1"/>
                            <html:text styleId="createTranslationWordId2" name="CreateTranslationActionForm" property="wordId2"/>
                        </div>
                        <div class="flex-space-around">
                            <html:text styleId="createTranslationWord1" name="CreateTranslationActionForm" property="word1" styleClass="createTranslationWord"/>
                            <div class="valign-wrapper">
                                <div class="center-align">
                                    <i class="material-icons">arrow_back_ios</i>
                                    <i class="material-icons">translate</i>
                                    <i class="material-icons">arrow_forward_ios</i>
                                </div>
                            </div>
                            <html:text styleId="createTranslationWord2" name="CreateTranslationActionForm" property="word2" styleClass="createTranslationWord"/>
                        </div>
                        <div class="center-align">
                            <html:submit styleId="createTranslationSubmit" styleClass="btn-flat white orange-text" value="Add Translation"/>
                        </div>
                    </html:form>
                </div>
            </div>
        </div>

        <script>
            const langId1 = '<%= lang1.getId()%>';
            const langId2 = '<%= lang2.getId()%>';
        </script>
        <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/js/materialize.min.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
