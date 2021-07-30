from tkinter import *
from datetime import date
from datetime import datetime
from tkinter import messagebox
from tkinter import filedialog
from tkinter.filedialog import askopenfilename

import tkinter as tk
import sys
import webbrowser

# Print data to config.php
def printpage():
	ctname = contestname.get()
	dsrtion = description.get()
	sttime = starttime.get()
	bgtime = begintime.get()
	drtime = duringtime.get()
	sbmtime = submittime.get()
	penbtn = penalty.get()
	pblic = public.get()
	scrbtn = scorepen.get()
	checkbnt = checkpent.get()
	direct = path.get()
	if checkbnt == 0:
		scrbtn = 0
	if drtime == "unlimited":
		drtime = 0
	fileout = open(direct, "w+")
	fileout.write("""<?php
	date_default_timezone_set("Asia/Bangkok"); 
	$contestName = "{0}";
	$description = "{1}";
	$problemsDir = "contests/problems";
	$examTestDir = "contests/test";
	$uploadDir 	= "contests/submit/";	
	$logsDir 	= "contests/submit/Logs/";
	$logssubDir = "contests/submit/Logs/";
	$hisDir 	= "contests/submit/History";
	$penDir	    = "contests/submit/Penalty";
	$startTime	= date_create("{2}",timezone_open("Asia/Bangkok")); 
	$begintime	= mktime({3}); 
	$duringTime = {4}; 
	$publish 	= {5};  
	$submitTime = {6};  
	$penalty 	= {7};  
	$score_pen 	= {8}; 
?>
	""".format(
		ctname, # Contest name
		dsrtion, # Contest description
		sttime, # Start time following format
		bgtime, # Begin time following format
		drtime, # During time
		pblic, # Public or not
		sbmtime, # Submit time
		penbtn, # Penalty
		scrbtn # Score_pen
	))
	messagebox.showinfo("Save", "Saved successfully!")

# Save action
def saveaction():
	ctname = contestname.get()
	dsrtion = description.get()
	sttime = starttime.get()
	bgtime = begintime.get()
	drtime = duringtime.get()
	sbmtime = submittime.get()
	penbtn = penalty.get()
	scrbtn = scorepen.get()
	pblic = public.get()
	print(ctname)
	print(penbtn)
	print(scrbtn)

# Reset data to default
def resetdefault():
	day_now = date.today()
	day = day_now.strftime("%m, %d, %Y")
	hour_now = datetime.now()
	hour = hour_now.strftime("%H, %M, %S")
	current_time = hour_now.strftime("%H:%M:%S")
	duringtime.set("unlimited")
	contestname.set("CVT ONLINE JUDGE")
	description.set("CVT CODE TEAM SINCE 2008")
	starttime.set(str(day_now) + " " +current_time)
	begintime.set(hour + ", " + day)
	submittime.set("5")
	scorepen.set(0)
	path.set("C:/xampp/htdocs/config.php")
	c1.select()
	c2.select()
	c3.select()
	e7.configure(state = "normal")
	e7.update()

# Disabled input entry
def disabledentry():
	statuscore = checkpent.get()
	if statuscore == 0:
		e7.configure(state = "disabled")
		e7.update()
	else:
		e7.configure(state = "normal")
		e7.update()
		c1.select() # Turn on penalty because if you want to minus the score of ctt you have to turn on penalty
# Sync button
def synconoff():
	statuspen = penalty.get()
	if statuspen == 0:
		c3.deselect()
		e7.configure(state = "disabled")
		e7.update()

# Select file
def selectfile():
	# file_selected = filedialog.askdirectory()
	file_selected = askopenfilename()
	print(file_selected)
	path.set(file_selected)	

def openlink():
	url = "http://facebook.com/devilc51.xyz"
	webbrowser.open_new_tab(url)

# Init Canvas
root = tk.Tk()
root.resizable(height = False, width = False)
root.minsize(height = 550, width = 570)
root.title("CFC - Created by Phan Thanh An")
root.configure(background='Light Gray')
root.iconbitmap('cfapp.ico')

# Valuable initialize
contestname = StringVar()
description = StringVar()
starttime = StringVar()
begintime = StringVar()
duringtime = StringVar()
submittime = StringVar()
path = StringVar()

scorepen = IntVar()
penalty = IntVar()
checkpent = IntVar()
public = IntVar()

# Set defaule value
day_now = date.today()
day = day_now.strftime("%m, %d, %Y")
hour_now = datetime.now()
time = hour_now.strftime("%H, %M, %S")
current_time = hour_now.strftime("%H:%M:%S")

duringtime.set(0)
contestname.set("CVT ONLINE JUDGE")
description.set("CVT CODE TEAM SINCE 2008")
starttime.set(str(day_now) + " " +current_time)
begintime.set(time + ", " + day)
submittime.set("5")
duringtime.set("unlimited")
scorepen.set(0)
path.set("C:/xampp/htdocs/config.php")

# Label init
lpath = Label(root, text = "Config path", font = "Helvetica 18 bold", bg = "Light Gray")
l0 = Label(root, text = "Config For Contest", fg = "purple", font = "Helvetica 20 bold", bg = "Light Gray")
l1 = Label(root, text = "Contest name", font = "Helvetica 18 bold", bg = "Light Gray")
l2 = Label(root, text = "Description", font = "Helvetica 18 bold", bg = "Light Gray")
l3 = Label(root, text = "Start Time", font = "Helvetica 18 bold", bg = "Light Gray")
l4 = Label(root, text = "Begin Time", font = "Helvetica 18 bold", bg = "Light Gray")
l5 = Label(root, text = "During Time", font = "Helvetica 18 bold", bg = "Light Gray")
l6 = Label(root, text = "Submit Time(s)", font = "Helvetica 18 bold", bg = "Light Gray")
l7 = Label(root, text = "Penalty", font = "Helvetica 18 bold", bg = "Light Gray")
l8 = Label(root, text = "Public", font = "Helvetica 18 bold", bg = "Light Gray")
l9 = Label(root, text = "Scrore Pen(%)", font = "Helvetica 18 bold", bg = "Light Gray")
lspace = Label(root, text = "")
l10 = Label(root, text = "", bg = "Light Gray")

# Print grid lable
l0.grid(row = 0, columnspan = 2)
lpath.grid(row = 1, column = 0, sticky = W, pady = 2)
l1.grid(row = 2, column = 0, sticky = W, pady = 2)
l2.grid(row = 3, column = 0, sticky = W, pady = 2)
l3.grid(row = 4, column = 0, sticky = W, pady = 2)
l4.grid(row = 5, column = 0, sticky = W, pady = 2)
l5.grid(row = 6, column = 0, sticky = W, pady = 2)
l6.grid(row = 7, column = 0, sticky = W, pady = 2)
l7.grid(row = 8, column = 0, sticky = W, pady = 2) 
l8.grid(row = 9, column = 0, sticky = W, pady = 2) 
l9.grid(row = 10, column = 0, sticky = W, pady = 2) 
lspace.grid(row = 11, column = 0, sticky = W, pady = 2) 
l10.grid(row = 15, column = 0,sticky = W, pady = 2) 
Label(root, text = "Author: Phan Thanh An - facebook.com/devilc51.xyz - CVT (K18 - K21)", fg = "red", bg = "#FFFF66", font = "Helvetica 12 bold", justify = CENTER).grid(row = 18, columnspan = 2)

# Endline button
Button(root, text = "...", command = selectfile, font = "Helvetica 12 bold", width = 2).grid(row = 1, column = 2)
Button(root, text = "   ", font = "Helvetica 12 bold", width = 2).grid(row = 2, column = 2)
Button(root, text = "   ", font = "Helvetica 12 bold", width = 2).grid(row = 3, column = 2)
Button(root, text = "   ", font = "Helvetica 12 bold", width = 2).grid(row = 4, column = 2)
Button(root, text = "   ", font = "Helvetica 12 bold", width = 2).grid(row = 5, column = 2)
Button(root, text = "   ", font = "Helvetica 12 bold", width = 2).grid(row = 6, column = 2)
Button(root, text = "   ", font = "Helvetica 12 bold", width = 2).grid(row = 7, column = 2)
Button(root, text = "FB", font = "Helvetica 12 bold", width = 2, bg = "#CCFF66", command = openlink).grid(row = 18, column = 2)
# Entry init
epath = Entry(root, width = 27, font = ("tamoha", 18), textvariable = path)
e1 = Entry(root, width = 27, font = ("tamoha", 18), textvariable = contestname)
e2 = Entry(root, width = 27, font = ("tamoha", 18), textvariable = description)
e3 = Entry(root, width = 27, font = ("tamoha", 18), textvariable = starttime)
e4 = Entry(root, width = 27, font = ("tamoha", 18), textvariable = begintime)
e5 = Entry(root, width = 27, font = ("tamoha", 18), textvariable = duringtime)
e6 = Entry(root, width = 27, font = ("tamoha", 18), textvariable = submittime)
e7 = Entry(root, width = 18, font = ("tamoha", 18), textvariable = scorepen)

# Print grid Entry
epath.grid(row = 1, column = 1, pady = 2)
e1.grid(row = 2, column = 1, pady = 2)
e2.grid(row = 3, column = 1, pady = 2)
e3.grid(row = 4, column = 1, pady = 2)
e4.grid(row = 5, column = 1, pady = 2)
e5.grid(row = 6, column = 1, pady = 2)
e6.grid(row = 7, column = 1, pady = 2)
e7.grid(row = 10, column = 1, pady = 2)

# Checkbox button
on_image = tk.PhotoImage(width = 48, height = 24)
off_image = tk.PhotoImage(width = 48, height = 24)
on_image.put(("green",), to = (0, 0, 23,23))
off_image.put(("red",), to = (24, 0, 47, 23))

c1 = tk.Checkbutton(root, image = off_image, selectimage = on_image, indicatoron = False, font = ("tamoha", 18), variable = penalty, command = synconoff)
c2 = Checkbutton(root, image = off_image, selectimage = on_image, indicatoron = False, font = ("tamoha", 18), variable = public)
c3 = Checkbutton(root, image = off_image, selectimage = on_image, indicatoron = False, font = ("tamoha", 18), variable = checkpent, command = disabledentry)

c1.select()
c2.select()
c3.select()
# Print grid checkbox button
c1.grid(row = 8, column = 1, sticky = W, columnspan = 2)
c2.grid(row = 9, column = 1, sticky = W, columnspan = 2)
c3.grid(row = 10, column = 1, sticky = W, columnspan = 2)


# Save button and reset button
frameButton = Frame()
Button(frameButton, text = "Save", command = printpage, fg = "green", font = "Helvetica 18 bold", height = 1, width = 7).pack(side = LEFT)
Button(frameButton, text = "Reset", command = resetdefault, fg = "green", font = "Helvetica 18 bold", height = 1, width = 7).pack(side = LEFT)
frameButton.grid(row = 12, columnspan = 2)

# __main__
mainloop()