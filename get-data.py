#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# vim: set et sw=4 ts=4 sts=4 ff=unix fenc=utf8:
# Author: Jeswang<wangyi724@gmail.com>
#         http://blog.jeswang.org
# Created on 2014-07-11 16:14:06

import os
import bs4
import requests

def createFile(fileName, content):
    with open(fileName, 'a') as file:
        file.write(content)
        file.close()

class BaseHandler:
    def __init__(self, soup=None):
        self.soup = soup;

class LCProblemHandler(BaseHandler):
    def run(self):
        problems = self.soup.find_all('tr')
        self.problem_names = []
        self.problem_dates = []
        self.problem_ac_rate = []
        self.problem_urls = []
        for i in problems:
            result = i.find_all('td')
            if len(result) > 0:
                self.problem_names += result[1].contents[0]
                self.problem_urls.append("http://oj.leetcode.com" + result[1].find('a')['href'])
                self.problem_dates.append(result[2].contents[0])
                self.problem_ac_rate.append(result[3].contents[0][:-1])

class QuestionHandler(BaseHandler):
    def run(self):
        textarea = self.soup.find("textarea", class_='cpp')
        self.cpp = textarea.get_text()
        
        question = self.soup.find(class_='question-content')
        self.description = question.get_text()

def generateHeader():
    r = requests.get("http://oj.leetcode.com/problems/")
    soup = bs4.BeautifulSoup(r.text)
    main_handler = LCProblemHandler(soup)
    main_handler.run()

    for i in range(len(main_handler.problem_urls)):
        url = main_handler.problem_urls[i]
        
        r = re.compile(r"""\/([\w-]*)\/$""")
        fileName = r.findall(url)[0]+".h"
        
        r = requests.get(url)
        soup = bs4.BeautifulSoup(r.text)
        handler = QuestionHandler(soup)
        handler.run()
        print("NO "+ str(i) + " Finished.")

        author = """//
//  %s
//
//  Created by %s %s.
//
""" % (fileName, autherName, date)

        comment = ("/*\nDescription:"+ handler.description+"*/").replace('\n\n', '\n')
        code = handler.cpp

        createFile(fileName, author + "\n" + comment + "\n\n" + code)

if __name__ == "__main__":
    generateHeader()
