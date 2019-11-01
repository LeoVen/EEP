<%-- 
    Document   : word.jsp
    Created on : 31/10/2019, 12:41:56
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@page import="eep.as.leoven.dao.WordDAO"%>
<%@page import="java.util.List"%>
<%@page import="eep.as.leoven.vo.Word"%>
<%@page import="eep.as.leoven.vo.Language"%>
<%@page import="eep.as.leoven.controller.PageContentController"%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    Language currentLanguage = PageContentController.getCurrentLanguage();

    List<Word> words = new WordDAO().getByLanguage(currentLanguage);
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

        <div class="centered-card">
            <div class="card">
                <div class="card-content">
                    <span class="card-title">Create words for <%= currentLanguage.getName() %></span>
                    <div class="listing">
                        <% if (words != null) { %>
                        <div class="collection">
                            <% for (Word word : words) {%>
                            <li class="collection-item">
                                <span class="languageNameText"><%= word.getWord()%></span>
                                <a href="javascript:deleteWordModal(<%= word.getId()%>, '<%= word.getWord()%>')" class="secondary-content">
                                    <i class="material-icons red-text">delete</i>
                                </a>
                                <a href="javascript:editWordModal(<%= word.getId()%>, '<%= word.getWord()%>')" class="secondary-content">
                                    <i class="material-icons blue-text">edit</i>
                                </a>
                            </li>
                            <% }%>
                        </div>
                        <% } else { %>
                        <p>You have not created any words for <%= currentLanguage.getName() %> yet...</p>
                        <% }%>
                    </div>
                </div>
                <div class="card-action center-align">
                    <a href="javascript:createLangModal()" class="btn green"><i class="material-icons">add</i></a>
                </div>
            </div>
        </div>

        <!-- MODALS -->
        <!-- CREATE WORD -->
        <div id="createWordModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Create Word</h4>
                    <html:form action="CreateWord">
                        <p class="error-message" id="createWordError"></p>
                        <html:text styleId="createWordName" name="CreateWordActionForm" property="word"/>
                        <div class="flex-space-between">
                            <html:submit styleId="createLanguageSubmit" value="Create" styleClass="btn blue"/>
                            <a href="#!" class="modal-close btn red">Cancel</a>
                        </div>
                    </html:form>
                    <html:errors/>
                </div>
            </div>
        </div>

        <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/js/materialize.min.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
