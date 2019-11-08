#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Nov  8 13:07:27 2019

@author: usuario
"""

import cv2
import numpy as np
from sklearn.svm import SVC
from sklearn.svm import SVR

# Read all images
microscopio1_g = cv2.imread('microscopio1.jpg')
microscopio2_g = cv2.imread('microscopio2.jpg')
microscopio3_g = cv2.imread('microscopio3.jpg')
microscopio4_g = cv2.imread('microscopio4.jpg')
microscopio5_g = cv2.imread('microscopio5.jpg')
test_microscopio4_g = cv2.imread('microscopio4.jpg')

# Resize images to 10px x 10px
microscopio1 = cv2.resize(microscopio1_g, (10,10))
microscopio2 = cv2.resize(microscopio2_g, (10,10))
microscopio3 = cv2.resize(microscopio3_g, (10,10))
microscopio4 = cv2.resize(microscopio4_g, (10,10))
microscopio5 = cv2.resize(microscopio5_g, (10,10))
test_microscopio4 = cv2.resize(test_microscopio4_g, (10,10))

# Concat all arrays to one
X = np.concatenate((microscopio1, microscopio2, microscopio3, microscopio4, microscopio5), axis=0)

# Create index to arrays
y = [1,2,3,4,5]

# Set y as a array
y = np.array(y)

# Reshape y
Y = y.reshape(-1)

# Reshape X with length of y
X = X.reshape(len(y), -1)

# Create the classifier 
classifier_linear = SVC(kernel='linear')

print(40 * '-')
print('Started train of SVC model')

# Train the classifier with images and indexes
classifier_linear.fit(X,Y)

print('Finished train')
print(40 * '-')

# Predict the category of image 
prediction = classifier_linear.predict(test_microscopio4.reshape(1,-1))

# Score of predict 
score = classifier_linear.score(X,Y)

# Show prediction
print('Result: {}'.format(prediction))

# Show prediction score
print('Score of precision: {:.1f}%'.format(score * 100))

# Set result as image of prediction
if prediction == 1:
	result = microscopio1_g
elif prediction == 2:
	result = microscopio2_g
elif prediction == 3:
	result = microscopio3_g
elif prediction == 4:
	result = microscopio4_g
elif prediction == 5:
	result = microscopio5_g

# Show image based on prediction
cv2.imshow("Result", result)
# Show the image tested
cv2.imshow("Test", test_microscopio4_g)
# Wait for key
cv2.waitKey(0)

print('---------------------------------------')


# Create the classifier 
classifier_linear_regression = SVR(kernel='linear')

print('Start SVR Train')

# Train the classifier with images and indexes
classifier_linear_regression.fit(X,Y)

print('Finished train')
print(40 * '-')

# Predict the category of image 
prediction = classifier_linear_regression.predict(test_microscopio4.reshape(1,-1))

# Score of predict 
score = classifier_linear_regression.score(X,Y)

# Show prediction
print('Result: {}'.format(prediction))

# Show prediction score
print('Score of precision: {:.1f}%'.format(score * 100))

# Set result as image of prediction
if prediction == 1:
	result = microscopio1_g
elif prediction == 2:
	result = microscopio2_g
elif prediction == 3:
	result = microscopio3_g
elif prediction == 4:
	result = microscopio4_g
elif prediction == 5:
	result = microscopio5_g

# Show image based on prediction
cv2.imshow("Result", result)
# Show the image tested
cv2.imshow("Test", test_microscopio4_g)
# Wait for key
cv2.waitKey(0)