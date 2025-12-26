# Security Policy

## Supported Versions

The following versions of Live Doodle on Camera are currently supported with security updates:

| Version | Supported          |
| ------- | ------------------ |
| 1.x.x   | :white_check_mark: |
| < 1.0   | :x:                |

## Reporting a Vulnerability

We take the security of Live Doodle on Camera seriously. If you have discovered a security vulnerability, we appreciate your help in disclosing it to us in a responsible manner.

### How to Report

**Please do NOT report security vulnerabilities through public GitHub issues.**

Instead, please report them via email to:

**Email**: chethana.workspace@gmail.com

**Subject Line**: [SECURITY] Brief description of vulnerability

### What to Include

Please include the following information in your report:

1. **Description** - Detailed description of the vulnerability
2. **Impact** - Potential impact of the vulnerability
3. **Steps to Reproduce** - Detailed steps to reproduce the issue
4. **Proof of Concept** - Code or screenshots demonstrating the issue
5. **Affected Versions** - Which versions are affected
6. **Suggested Fix** - If you have recommendations
7. **Your Contact Information** - For follow-up questions

### Example Report

```
Subject: [SECURITY] Buffer Overflow in Image Processing

Description:
A buffer overflow vulnerability exists in the image processing 
module when handling specially crafted PNG files.

Impact:
Could allow arbitrary code execution when loading malicious images.

Steps to Reproduce:
1. Create a PNG file with oversized metadata
2. Load the file using File > Open
3. Application crashes

Affected Versions:
All versions prior to 1.2.0

Suggested Fix:
Implement bounds checking in loadImage() function.
```

## Response Timeline

We will make every effort to respond to security reports according to the following timeline:

- **Initial Response**: Within 48 hours
- **Status Update**: Within 7 days
- **Fix Development**: Within 30 days (depending on severity)
- **Public Disclosure**: After patch is released

## Severity Levels

We classify vulnerabilities using the following severity levels:

### Critical

- Remote code execution
- Privilege escalation
- Data corruption or loss

**Response**: Immediate attention, hotfix within 48-72 hours

### High

- Denial of service
- Information disclosure
- Authentication bypass

**Response**: Fix within 7 days

### Medium

- Limited information disclosure
- Minor denial of service

**Response**: Fix in next regular release

### Low

- Minor bugs with security implications
- Hardening opportunities

**Response**: Fix when convenient

## Security Best Practices

### For Users

1. **Keep Software Updated**
   - Always use the latest version
   - Enable automatic updates if available

2. **Trusted Sources Only**
   - Download only from official repositories
   - Verify checksums of downloaded files

3. **Camera Permissions**
   - Review camera access permissions
   - Disable when not in use

4. **File Handling**
   - Be cautious with project files from unknown sources
   - Scan files with antivirus before opening

### For Developers

1. **Input Validation**
   - Validate all user inputs
   - Sanitize file paths and names
   - Check image dimensions and formats

2. **Memory Safety**
   - Use RAII for resource management
   - Prefer smart pointers over raw pointers
   - Implement bounds checking

3. **Dependency Management**
   - Keep OpenCV and dependencies updated
   - Monitor security advisories
   - Use dependency scanning tools

4. **Code Review**
   - Security-focused code reviews
   - Static analysis tools
   - Fuzzing for input handling

## Known Security Considerations

### Camera Access

This application requires camera access to function. Users should be aware:

- Camera feed is processed locally
- No data is transmitted over network
- Camera access can be revoked via OS settings

### File System Access

The application requires file system access for:

- Reading configuration files
- Saving exported images
- Loading custom resources

All file operations are confined to:
- User's home directory
- Application data directory
- User-selected save locations

### Third-Party Dependencies

- **OpenCV**: Monitor [OpenCV Security Advisories](https://github.com/opencv/opencv/security/advisories)
- **CMake**: Keep build tools updated
- **Compiler**: Use latest stable compiler versions

## Disclosure Policy

When a security issue is resolved:

1. A security advisory will be published on GitHub
2. The issue will be documented in CHANGELOG.md
3. CVE identifier will be requested for critical issues
4. Public disclosure will occur after users have had time to update

## Security Hall of Fame

We recognize and thank security researchers who responsibly disclose vulnerabilities:

*No vulnerabilities reported yet*

---

Thank you for helping keep Live Doodle on Camera and its users safe!

Last Updated: December 2025
