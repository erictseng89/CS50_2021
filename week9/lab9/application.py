import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")
BIRTHDAYS = db.execute("SELECT * FROM birthdays")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        if not name:
            return render_template("error.html", message="Invalid or Missing Name")
        month = request.form.get("month")
        month = int(month)
        if not 1 <= month <= 12:
            return render_template("error.html", message="Invalid or Missing Month")
        day = request.form.get("day")
        day = int(day)
        if not 1 <= day <= 31:
            return render_template("error.html", message="Invalid or Missing Day")
            
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)

        return redirect("/")

    else:
        return render_template("index.html", birthdays = BIRTHDAYS)


