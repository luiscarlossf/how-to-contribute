from flask import render_template
from flask import url_for, redirect
# Import Request object to use
from flask import request

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
	# elif request.method == "POST":
	# 	userID = request.form['userid']
	# 	password = request.form['loginpassword']
	# 	# Can perform some password validation here!
	# 	return "Login Successful for: %s" % userID
