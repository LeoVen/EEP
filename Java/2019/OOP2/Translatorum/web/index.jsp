<%-- 
    Document   : index.jsp
    Created on : 31/10/2019, 03:00:47
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="java.util.Set"%>
<%@page import="eep.as.leoven.controller.ApplicationController"%>
<%@page import="eep.as.leoven.dao.LanguageDAO"%>
<%@page import="eep.as.leoven.vo.User"%>
<%@page import="eep.as.leoven.vo.Language"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    // Prevent caching
    if (ApplicationController.isNoCaching()) {
        response.setDateHeader("Expires", 0);
    }

    User user = ApplicationController.getCurrentUser();
%>

<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="css/materialize.css">
        <link rel="stylesheet" href="css/main.css">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Translatorum</title>
    </head>
    <body>

        <% if (user == null) {%>
        <div class="centered-card">
            <div class="card"  style="width: 400px;">
                <html:form action="Login">
                    <div class="card-content">
                        <span class="card-title">Login</span>
                        <div class="input-field">
                            <label for="loginUserName">User Name</label>
                            <html:text styleId="loginUserName" name="LoginActionForm" property="userName"/>
                        </div>
                        <div class="input-field">
                            <label for="loginUserPassword">Password</label>
                            <html:password styleId="loginUserPassword" name="LoginActionForm" property="userPassword"/>
                        </div>
                    </div>
                    <div class="card-action">
                        <html:submit styleId="loginSubmit" value="Login" styleClass="btn-flat white orange-text"/>
                        <a class="activator btn-flat white orange-text"><span class="activator">Signup</span></a>
                    </div>
                </html:form>
                <div class='card-reveal'>
                    <html:form action="Signup">
                        <span class="card-title">Signup <i class="material-icons right">close</i></span>
                        <div class="input-field">
                            <label for="signupUserName">User Name</label>
                            <html:text styleId="signupUserName" name="SignupActionForm" property="userName"/>
                        </div>
                        <div class="input-field">
                            <label for="signupUserPassword">Password</label>
                            <html:password styleId="signupUserPassword" name="SignupActionForm" property="userPassword"/>
                        </div>
                        <div class="center-align">
                            <html:submit styleId="signupSubmit" value="Signup" styleClass="btn-flat white orange-text"/>
                        </div>
                    </html:form>
                </div>
            </div>
        </div>
        <% } else {
                response.sendRedirect("main.jsp");
            }%>

        <script src="js/jquery-3.4.1.js"></script>
        <script src="js/materialize.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
