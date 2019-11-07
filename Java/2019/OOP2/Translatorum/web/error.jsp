<%-- 
    Document   : error
    Created on : 26/10/2019, 00:27:03
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page isErrorPage="true" %>
<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="css/materialize.css">
        <link rel="stylesheet" href="css/main.css">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Translatorum - Error</title>
    </head>
    <body>
        <div class="error-center card">
            <div class="card-content">
                <span class="card-title">Error</span>
                <p>Something went wrong...</p>
                <% if (exception != null) {%>
                <p><%= exception.getMessage()%></p>
                <p><%= exception.getCause()%></p>
                <% exception.printStackTrace(); %>
                <% }%>
                <html:errors/>
                <div class="center-align">
                    <br>
                    <a href="index.jsp" class="btn">Return</a>
                </div>
            </div>
        </div>

        <script src="js/jquery-3.4.1.js"></script>
        <script src="js/materialize.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
