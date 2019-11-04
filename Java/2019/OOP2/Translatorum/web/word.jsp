<%-- 
    Document   : word.jsp
    Created on : 31/10/2019, 12:41:56
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
                    <span class="card-title">Create words for <%= currentLanguage.getName()%></span>
                    <div class="listing">
                        <% if (words != null) { %>
                        <ul class="collection">
                            <% for (Word word : words) {%>
                            <li class="collection-item">
                                <span class="listingText"><%= word.getWord()%></span>
                                <a href="javascript:deleteWordModal(<%= word.getId()%>, '<%= word.getWord()%>')" class="secondary-content">
                                    <i class="material-icons red-text">delete</i>
                                </a>
                                <a href="javascript:editWordModal(<%= currentLanguage.getId()%>, <%= word.getId()%>, '<%= word.getWord()%>')" class="secondary-content">
                                    <i class="material-icons blue-text">edit</i>
                                </a>
                            </li>
                            <% }%>
                        </ul>
                        <% } else {%>
                        <p>You have not created any words for <%= currentLanguage.getName()%> yet...</p>
                        <% }%>
                    </div>
                </div>
                <div class="card-action center-align">
                    <a href="javascript:createWordModal(<%= currentLanguage.getId()%>, '<%= currentLanguage.getName()%>')" class="btn green"><i class="material-icons">add</i></a>
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
                        <div class="row">
                            <div class="col s2 margin0">
                                <html:text styleId="createWordLanguageId" name="CreateWordActionForm" property="languageId"/>
                            </div>
                            <div class="col s10">
                                <html:text styleId="createWordLanguageName" name="CreateWordActionForm" property="languageName"/>
                            </div>
                        </div>
                        <html:text styleId="createWordWord" name="CreateWordActionForm" property="word"/>
                        <div class="flex-space-between">
                            <html:submit styleId="createWordSubmit" value="Create" styleClass="btn blue"/>
                            <a href="#!" class="modal-close btn red">Cancel</a>
                        </div>
                    </html:form>
                </div>
            </div>
        </div>

        <!-- EDIT WORD -->
        <div id="editWordModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Edit Word</h4>
                    <html:form action="UpdateWord">
                        <div class="row">
                            <div class="col s2 margin0">
                                <html:text styleId="editWordId" name="UpdateWordActionForm" property="wordId"/>
                            </div>
                            <div class="col s10">
                                <html:text styleId="editWordWord" name="UpdateWordActionForm" property="word"/>
                            </div>
                        </div>
                        <div class="display-none">
                            <html:text styleId="editWordLanguageId" name="UpdateWordActionForm" property="languageId" styleClass="display-none" />
                        </div>
                        <div class="flex-space-between">
                            <html:submit styleId="editWordSubmit" value="Update" styleClass="btn blue"/>
                            <a href="#!" class="modal-close btn red">Cancel</a>
                        </div>
                    </html:form>
                </div>
            </div>
        </div>

        <!-- DELETE WORD -->
        <div id="deleteWordModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Delete Word</h4>
                    <p>Are you sure you want to delete this Word? </p>
                    <p>This action will delete all the translations that are associated with it.</p>
                    <html:form action="DeleteWord">
                        <div class="row">
                            <div class="col s2 margin0">
                                <html:text styleId="deleteWordId" name="DeleteWordActionForm" property="wordId"/>
                            </div>
                            <div class="col s10">
                                <html:text styleId="deleteWordWord" name="DeleteWordActionForm" property="word"/>
                            </div>
                        </div>
                        <div class="flex-space-between">
                            <html:submit styleId="deleteWordSubmit" value="Delete" styleClass="btn blue"/>
                            <a href="#!" class="modal-close btn red">Cancel</a>
                        </div>
                    </html:form>
                </div>
            </div>
        </div>

        <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/js/materialize.min.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
