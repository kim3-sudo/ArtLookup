# Adding Contributions Using Branches and Pull Requests

Branches allow you to more easily revert and track changes. If you make a giant mistake and everything is breaking, you can just kill the branch, saving yourself from making tons of `git reverts` and muddying the project with commits.

To use:

1. At the beginning of your coding session, feature addition, or bug fix, make a new branch.
  * In Git Bash, use the command `git checkout -b <branch>`, where <branch> represents the name of your new branch. Don't use spaces!
  * In GitHub online, at the upper left, click on the master branch, then start typing the name of your new branch. Don't use spaces!
  * If you've already made your branch, and you'd like to reopen the branch:
    * In Git Bash, use the command `git checkout <branch>`, where <branch> represents the name of an existing branch. Don't include the opening and closing chevrons.
    * In GitHub online, at the upper left, select the master branch, then select the name of the existing branch in the dropdown.
  * Please don't make branches more than two levels in. That is, off of master, don't make a branch `kim3-sudo-patch-1`, make a branch off of that branch named `kim3-sudo-patch-1-1`, then make a third sub-branch named `kim3-sudo-patch-1-1-1`, unless you have a really good reason to do so.
2. Now that you're in your new branch, you can begin making changes. By default, Git and GitHub will commit changes to the active branch, not the master branch. Think of this new branch like a brand-new repository that you can make any changes you want.
  * If you're using Git Bash, you might be asked to set your upstream. To do so, run `git push --set-upstream origin <branch>` where <branch> is the name of the active branch.
3. When you're done and you commit, add your commit message the same way, whether you're in Git Bash or on GitHub online. However, instead of committing to master, you'll commit to your branch.
4. When you've finished with the branch, you can merge that branch back into the master branch. Similar to how a commit and push will merge changes to the master branch, a branch merge will merge all of the changes back into the master branch. To do so:
  * In GitHub online (the only way that I've gotten to work):
    1. Go back to the root directory of the repository.
    2. Above the list of files, you should see a button to make a new pull request; click it.
    3. In the new screen that shows, add your messages. These are similar to commit messages, but you can be more broad. That is, instead of "Edited main.cpp, line 45", you can say "Added a login system". If someone wants to know exactly what you did, they can open up the pull request and the closed branch to view the commit messages that you made to the branch.
    4. Make the pull request.
    5. If merging the branch would cause a merge conflict, you'll be prompted to resolve these now; GitHub will report that your branch cannot automatically be merged. Otherwise, you'll see that the active branch has no conflicts with the base branch.
    6. Click the button to merge the pull request, then confirm the merge.
    7. If everything works correctly, you'll see that your branch has been successfully merged, and that the branch can now safely closed and deleted. Please delete your merged branches!
    
