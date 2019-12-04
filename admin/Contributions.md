# Adding Contributions Using Branches and Pull Requests

Branches allow you to more easily revert and track changes. If you make a giant mistake and everything is breaking, you can just kill the branch, saving yourself from making tons of `git revert`s and muddying the project with commits.

 
## tl;dr

1. Make or checkout a branch.
2. Make edits to the branch.
3. When you're done, make a pull request and merge the branch into the origin branch or the master branch.
4. Delete the branch.

## Longer and more detailed docs:

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

## Merging and Branch Management Cheat Sheet

* `git checkout <branch>`: check out (switch to) an existing <branch>
* `git checkout -b <branch>`: make and check out a new <branch>
* `git branch`: list the branches; an asterisk will show up next to the active branch
* Pull request: think mega-commit that modifies the origin branch. This commit that has lots of "baby-commits" that were done to the active branch
* Branch: a version of the repository that can be used for editing and testing, before the new code is fully implemented
* Master branch: exactly what it sounds like, it's the branch that everything comes from and goes back to
* Origin branch: the branch that a checked-out branch has been checked-out from; the master branch will almost always be the origin branch
