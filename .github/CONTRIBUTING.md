# How-to contribute

Those are the main contributing guidelines for contributing to this project:

- Verify that your contribution does not embark proprietary code or infringe any copyright of any sort.
- Avoid adding any unnecessary dependencies to the project, especially of those are not easily packaged and installed through `brew` or `apt-get`.
- C/C++ contributions must follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#Run-Time_Type_Information__RTTI_).
- Use [Pull Request](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-requests) mechanism and please be patient while waiting for reviews.
- Remain polite and civil in all exchanges with the maintainers and other contributors.
- Any issue submitted which does not respect provided template, or lack of information, will be considered as invalid and automatically closed.

## Get started

In order to contribute, the safest is to create your [own fork of jsonCPP](https://help.github.com/en/github/getting-started-with-github/fork-a-repo) first. The following set of commands will clone this new repository, create a virtual environment provisioned with the dependencies and run the tests (will take a few minutes):

```bash
git clone https://github.com/<user-name>/jsonCPP && cd jsonCPP
```

You can then make your changes and experiment freely. Once you're done, remember to check that the tests still run. If you've added a new feature, add tests!

Then finally, you're more than welcome to create a [Pull Request](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request-from-a-fork) in **jsonCPP** main repo. We will look at it as soon as possible and eventually integrate your changes in the project.
