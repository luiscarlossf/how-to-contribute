from flask import render_template

# Imported a function to render templates

from app import app

@app.route('/hello/<name>')
def hello_name(name):
	return "Hello, %s!" % name

@app.route('/blog/<int:postID>')
def show_blog(postID):
	return "Blog Number: %d" % postID

@app.route('/blog/<float:revNo>')
def revision(revNo):
	return "Revision Number: %f" % revNo