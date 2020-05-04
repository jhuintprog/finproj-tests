# Final project tests

This git repository contains community-written unit tests and driver program tests for the
[Intermediate Programming final project](https://jhuintprog.github.io/spring2020/finproj/index.html).

## Shared unit tests

The [tests](tests) directory has the shared unit test programs.  You are welcome to use these. Even better, we invite you to *improve* them!

## Shared driver program tests

The [data](data) directory has example game files, and the [input](input) and [expected](expected) directories have example driver program inputs and expected outputs that you can use to test your driver program.

Here are a couple of scenarios you can try (these assume that you've copied the files into your project repository):

```
mkdir -p actual
./minotaur data/mazeSolo.txt < input/mazeSoloSuccessInput.txt > actual/mazeSoloSuccessOutput.txt
diff -u expected/mazeSoloSuccessOutput.txt actual/mazeSoloSuccessOutput.txt
./minotaur data/mazeSolo.txt < input/mazeSoloCollideWallInput.txt > actual/mazeSoloCollideWallOutput.txt
diff -u expected/mazeSoloCollideWallOutput.txt actual/mazeSoloCollideWallOutput.txt
```

If either of the `diff` commands produces output, it means that your driver program did not generate the expected output.

## Contributing improved tests

If you would like to contribute your improvements, please do the following:

1. Create a fork of this repository
2. Clone your fork
3. Commit your improvements to your fork
4. Create a pull request

We even made a video showing how to do this! Just click on this link: <https://youtu.be/LktYVsVcyks>.

We will periodically merge pull requests, so you should occasionally pull changes from this repository to make sure you have the latest versions of each test program.

If you would like help using or contributing to the public tests, please post a question on Piazza.

Here are some information resources that will be helpful:

* Forking a Github repository: <https://help.github.com/en/github/getting-started-with-github/fork-a-repo>
* How to create a pull request: <https://opensource.com/article/19/7/create-pull-request-github>

You can pull the latest changes from this repository into your local clone of your fork using the following command:

```
git pull https://github.com/jhuintprog/finproj-tests.git master
```

You will want to run the `pull` command above periodically so that your repository stays current with the latest contributions.  When updated tests arrive, you can copy them into your team repository in order to try them out.

**Important**: this is a public git repository, and if you submit a pull request and we accept it, your name and email will be in the commit history! If you would like to submit an improved test program privately, you can email it to [daveho@cs.jhu.edu](mailto:daveho@cs.jhu.edu), and we will merge it. Please use the email subject "final project unit test contribution".
