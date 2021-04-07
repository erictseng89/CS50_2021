from flask import Flask, render_template, request, redirect
from flask_mail import Mail, Message
from cs50 import SQL

app = Flask(__name__)

SPORTS = [
	"Dodgeball",
	"Flag Football",
	"Soccer",
	"Volleyball",
	"Ultimate Frisbee"
]

# REGISTRANTS = {}

db = SQL("sqlite:///froshims.db")

@app.route("/")
def index():
	return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
	name = request.form.get("name")
	if not name:
		return render_template("error.html", message="Missing Name")
	sport = request.form.get("sport")
	if not sport:
		return render_template("error.html", message="Missing Sport")
	if sport not in SPORTS:
		return render_template("error.html", message="Invalid Sport")
	
	db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
	
	return redirect("/registrants")

@app.route("/registrants")
def registrants():
	registrants = db.execute("SELECT * FROM registrants")
	return render_template("registrants.html", registrants=registrants)