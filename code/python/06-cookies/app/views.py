from flask import render_template
from flask import url_for, redirect
from flask import request
# Importing make_response to create Response Object
from flask import make_response

from app import app

@app.route('/')
@app.route('/index')
def index():
	user = {'nickname': 'Mitesh'}
	posts = [
		{
			'author': {'nickname': 'Mitesh'},
			'body': 'Beautiful Day in Hyderabad!'
		},
		{
			'author': {'nickname': 'Mitesh'},
			'body': 'Andhadhun Movie was so cool.'
		}
	]
	return render_template('index.html',title='Home',user=user,posts=posts)

@app.route('/about')
def about():
	return render_template('about.html')

@app.route('/login')
def login():
	return render_template('login.html')

@app.route('/loginNext',methods=['GET','POST'])
def loginNext():
	# To find out the method of request, use 'request.method'
	if request.method == "GET":
		print request.args
		userID = request.args.get("userid")
		password = request.args.get("loginpassword")
		# Can perform some password validation here
		return "Login Successful for: %s" % userID
	elif request.method == "POST":
		userID = request.form['userid']
		password = request.form['loginpassword']
		# Can perform some password validation here!
		return "Login Successful for: %s" % userID

@app.route('/setCookie',methods=['GET','POST'])
def setCookie():
	if request.method == "POST":
		userID = request.form['userid']
		# Create the Response Object
		resp = make_response(render_template('landing.html'))
		# Set the cookie value. Will use this name to refer to the cookies later
		resp.set_cookie('userID',userID)
		return resp

@app.route('/readCookie')
def readCookie():
	# Get all the cookies in request.cookies and then get the cookie named userID
	userID = request.cookies.get('userID')
	return '<h1>Hello '+ userID +' !!</h1>'
