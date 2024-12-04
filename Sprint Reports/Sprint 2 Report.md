# Sprint 2 Report 
Video Link: https://youtu.be/s2-X6ZMs-LQ
## What's New (User Facing)
 * Created data analytics
 * Created payment verification
 * Started on front end

## Work Summary (Developer Facing)
During Sprint 2, we started work on the front end side of our project, as well as finished work on other essential features of our project that were more difficult and time consuming, such as creating a class that analyzed data related to menu orders over a span of time, and creating a method to verify payment by having the user input a fake credit card number and checking if that number is present within a pre-existing text file with a number of fake credit card numbers already in it.

## Unfinished Work
We didn’t get to implement a revenue tracker yet because we didn’t feel that we had enough time during this sprint to create and test code for a potential revenue tracker for our project yet. We also still have to fully complete the front end side of our project because we ran into some issues that took more time to resolve than expected.

## Completed Issues/User Stories
Here are links to the issues that we completed in this sprint:

 * https://github.com/KellamA/322DineAutoProject/issues/1
 * https://github.com/KellamA/322DineAutoProject/issues/6
 * https://github.com/KellamA/322DineAutoProject/issues/9
 * https://github.com/KellamA/322DineAutoProject/issues/11 

 ## Incomplete Issues/User Stories
 Here are links to issues we worked on but did not complete in this sprint:
 
 * https://github.com/KellamA/322DineAutoProject/issues/12 (Didn't have enough time) 
 * https://github.com/KellamA/322DineAutoProject/issues/8 (Didn't have enough time)
 * https://github.com/KellamA/322DineAutoProject/issues/13 (Ran into some complications)

## Code Files for Review
Please review the following code files, which were actively developed during this sprint, for quality:
 * https://github.com/KellamA/322DineAutoProject/blob/main/main.cpp
 * https://github.com/KellamA/322DineAutoProject/blob/main/orderDataBase.cpp
 * https://github.com/KellamA/322DineAutoProject/blob/main/shoppingCart.cpp 
 * https://github.com/KellamA/322DineAutoProject/blob/main/analytics.cpp 
 
## Retrospective Summary
Here's what went well:
  * Using a text file to store credit cards made it easy to go through each line, store each credit card into a vector, then iterate through the entire vector to see if the credit card entered by the user is valid
  * Using a vector for the order database allowed us to continually add new orders into the database without having to constantly resize it
  * Using a switch to separate login for the customer, admin, and analytics was a good decision because it made our code easier to navigate

 Here's what we'd like to improve:
  * Work even more on the project throughout the week instead of doing a lot of singular days
  * Start on the next sprint even earlier so we have even more time to ask questions and debug our code
  * Meet up with each other more often to make sure everyone is making appropriate progress on their part of the project
  * Make sure our parts are fully complete and working properly before the deadline of the next sprint

Here are changes we plan to implement in the next sprint:
   * Make use of office hours when we’re stuck in order to get ideas on what to do/how to fix existing code
  * Start to implement code for Revenue Tracker and finish up our project as a whole
  * Finish front end
