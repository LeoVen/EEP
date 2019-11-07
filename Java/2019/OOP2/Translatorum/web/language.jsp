<%-- 
    Document   : language.jsp
    Created on : 24/10/2019, 02:08:04
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="eep.as.leoven.controller.ApplicationController"%>
<%@page import="eep.as.leoven.dao.LanguageDAO"%>
<%@page import="eep.as.leoven.vo.Language"%>
<%@page import="java.util.Set"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    // Check user login
    if (ApplicationController.getCurrentUser() == null) {
        response.sendRedirect("unauthorized.jsp");
    }

    // Prevent caching
    if (ApplicationController.isNoCaching()) {
        response.setDateHeader("Expires", 0);
    }

    Set<Language> languages = new LanguageDAO().getAll();
%>

<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="css/materialize.css">
        <link rel="stylesheet" href="css/main.css">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Translatorum - Languages</title>
    </head>
    <body>
        <!-- FAB -->
        <div class="fixed-action-btn">
            <a href="index.jsp" class="btn-floating btn-large orange">
                <i class="larg material-icons">keyboard_return</i>
            </a>
        </div>

        <!-- MAIN CARD -->
        <div class="centered-card">
            <div class="card">
                <div class="card-content">
                    <span class="card-title">Languages</span>
                    <div class="listing">
                        <ul class="collection">
                            <% for (Language language : languages) {%>
                            <li class="collection-item">
                                <span class="listingText"><%= language.getName()%></span>
                                <a href="javascript:deleteLangModal(<%= language.getId()%>, '<%= language.getName()%>')" class="secondary-content">
                                    <i class="material-icons red-text">delete</i>
                                </a>
                                <a href="javascript:editLangModal(<%= language.getId()%>, '<%= language.getName()%>')" class="secondary-content">
                                    <i class="material-icons blue-text">edit</i>
                                </a>
                            </li>
                            <% }%>
                        </ul>
                    </div>
                </div>
                <div class="card-action center-align">
                    <a href="javascript:createLangModal()" class="btn green"><i class="material-icons">add</i></a>
                </div>
            </div>
        </div>

        <!-- MODALS -->
        <!-- CREATE LANGUAGE -->
        <div id="createLanguageModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Create Language</h4>
                    <html:form action="CreateLanguage">
                        <html:text styleId="createLanguageName" name="CreateLanguageActionForm" property="languageName"/>
                        <div class="flex-space-between">
                            <html:submit styleId="createLanguageSubmit" value="Create" styleClass="btn blue"/>
                            <a href="#!" class="modal-close btn red">Cancel</a>
                        </div>
                    </html:form>
                    <html:errors/>
                </div>
            </div>
        </div>

        <!-- EDIT LANGUAGE -->
        <div id="editLanguageModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Edit Language</h4>
                    <html:form action="UpdateLanguage">
                        <div class="row">
                            <div class="col s2 margin0">
                                <html:text styleId="editLanguageId" name="UpdateLanguageActionForm" property="languageId"/>
                            </div>
                            <div class="col s10">
                                <html:text styleId="editLanguageName" name="UpdateLanguageActionForm" property="languageName"/>
                            </div>
                        </div>
                        <div class="flex-space-between">
                            <html:submit styleId="editLanguageSubmit" value="Update" styleClass="btn blue"/>
                            <a href="#!" class="modal-close btn red">Close</a>
                        </div>
                    </html:form>
                </div>
            </div>
        </div>

        <!-- DELETE LANGUAGE -->
        <div id="deleteLanguageModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Delete Language</h4>
                    <p>Are you sure you want to delete this Language? </p>
                    <p>This action will delete all the words and translations associated with it.</p>
                    <html:form action="DeleteLanguage">
                        <div class="row">
                            <div class="col s2 margin0">
                                <html:text styleId="deleteLanguageId" name="DeleteLanguageActionForm" property="languageId"/>
                            </div>
                            <div class="col s10">
                                <input id="deleteLanguageName" type="text"/>
                            </div>
                        </div>
                        <div class="flex-space-between">
                            <html:submit value="Delete" styleClass="btn blue"/>
                            <a href="#!" class="modal-close btn red">Close</a>
                        </div>
                    </html:form>
                </div>
            </div>
        </div>
        <!-- END MODALS -->

        <script src="js/jquery-3.4.1.js"></script>
        <script src="js/materialize.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
