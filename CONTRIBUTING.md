# Contributing to Live Doodle on Camera

Thank you for considering contributing to this project. This document outlines the guidelines and best practices for contributing.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Commit Guidelines](#commit-guidelines)
- [Pull Request Process](#pull-request-process)
- [Testing](#testing)
- [Documentation](#documentation)

## Code of Conduct

This project adheres to a Code of Conduct that all contributors are expected to follow. Please read [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) before contributing.

## Getting Started

### Prerequisites

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10 or higher
- OpenCV 4.x
- Git

### Setting Up Development Environment

1. Fork the repository
2. Clone your fork:
   ```bash
   git clone https://github.com/YOUR_USERNAME/live-doodle-on-cam.git
   cd live-doodle-on-cam
   ```
3. Add upstream remote:
   ```bash
   git remote add upstream https://github.com/chetx27/live-doodle-on-cam.git
   ```
4. Create a development branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```

## Development Workflow

### Branch Naming Convention

- `feature/description` - New features
- `bugfix/description` - Bug fixes
- `hotfix/description` - Critical fixes
- `docs/description` - Documentation updates
- `refactor/description` - Code refactoring
- `test/description` - Test additions or modifications

### Keeping Your Fork Updated

```bash
git fetch upstream
git checkout master
git merge upstream/master
```

## Coding Standards

### Style Guide

This project follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) with the following specifications:

#### Naming Conventions

```cpp
// Classes and Structs - PascalCase
class DrawingEngine { };

// Functions and Methods - camelCase
void drawShape();

// Variables - camelCase
int brushSize;

// Constants - UPPER_SNAKE_CASE
const int MAX_UNDO_LEVELS = 20;

// Private members - camelCase with trailing underscore
private:
    int brushSize_;
```

#### Code Formatting

- Indentation: 4 spaces (no tabs)
- Line length: Maximum 100 characters
- Braces: Same line for functions, control statements

```cpp
void function() {
    if (condition) {
        // code
    } else {
        // code
    }
}
```

#### Comments

```cpp
/**
 * @brief Brief description of function
 * @param param1 Description of parameter
 * @return Description of return value
 */
int calculateValue(int param1);

// Single line comments for brief explanations
int value = 0;  // Inline comment
```

### Code Quality

- Write self-documenting code
- Avoid magic numbers (use named constants)
- Keep functions focused and small (<50 lines)
- Use RAII for resource management
- Prefer `const` and `constexpr` where applicable
- Use smart pointers over raw pointers

## Commit Guidelines

### Commit Message Format

```
<type>(<scope>): <subject>

<body>

<footer>
```

#### Types

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, no logic change)
- `refactor`: Code refactoring
- `perf`: Performance improvements
- `test`: Test additions or modifications
- `chore`: Build process or auxiliary tool changes

#### Examples

```
feat(drawing): Add polygon drawing tool

Implemented polygon tool with click-to-add-vertex functionality.
Includes real-time preview and completion on double-click.

Closes #42
```

```
fix(undo): Correct undo stack overflow issue

Fixed memory leak when undo stack exceeded maximum levels.
Now properly removes oldest entries when at capacity.

Fixes #38
```

## Pull Request Process

### Before Submitting

1. **Update your branch** with latest upstream changes
2. **Test thoroughly** - Ensure all functionality works
3. **Run code formatting** - Follow style guidelines
4. **Update documentation** - If adding features
5. **Add tests** - For new functionality
6. **Update CHANGELOG.md** - Document your changes

### PR Title Format

```
[Type] Brief description
```

Examples:
- `[Feature] Add text annotation tool`
- `[Fix] Resolve camera initialization bug`
- `[Docs] Update installation instructions`

### PR Description Template

```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Breaking change
- [ ] Documentation update

## Testing
Describe testing performed

## Checklist
- [ ] Code follows style guidelines
- [ ] Self-review completed
- [ ] Comments added for complex code
- [ ] Documentation updated
- [ ] No new warnings generated
- [ ] Tests added/updated
- [ ] CHANGELOG.md updated

## Screenshots (if applicable)

## Related Issues
Closes #issue_number
```

### Review Process

1. Automated checks must pass
2. At least one maintainer approval required
3. All review comments must be addressed
4. No merge conflicts
5. CI/CD pipeline passes

## Testing

### Manual Testing

Test all drawing tools:
- Brush, Eraser, Line, Rectangle, Circle, Ellipse, Spray, Fill
- Color selection and brush size adjustment
- Undo/Redo functionality
- Save functionality
- Keyboard shortcuts

### Platform Testing

Test on:
- Linux (Ubuntu 20.04+)
- macOS (10.15+)
- Windows (10+)

### Performance Testing

- Verify 30+ FPS at 720p resolution
- Test memory usage over extended sessions
- Verify undo/redo stack memory management

## Documentation

### Code Documentation

- Add Doxygen-style comments for all public APIs
- Document complex algorithms
- Include usage examples

### User Documentation

- Update README.md for new features
- Add screenshots/GIFs for visual features
- Update API.md for API changes

## Feature Priorities

### High Priority

- Hand gesture recognition (MediaPipe)
- Video recording functionality
- Text annotation tool
- Multi-layer support

### Medium Priority

- Custom color picker
- Background blur/freeze
- Brush textures
- Import/export project files

### Low Priority

- Plugin system
- Cloud sync
- Mobile app
- Collaborative drawing

## Need Help?

- Check existing issues and pull requests
- Review documentation in `/docs`
- Open a discussion for questions
- Contact maintainers via GitHub

## Recognition

All contributors will be recognized in:
- README.md contributors section
- Release notes
- Project credits

Thank you for contributing to Live Doodle on Camera!
