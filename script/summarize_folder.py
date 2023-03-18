import os

# Replace "path/to/directory" with the path to your directory
directory = "."

# Get a list of all directories in the given directory
directories = [d for d in os.listdir(directory) if os.path.isdir(os.path.join(directory, d))]

# Sort the list of directories alphabetically
directories.sort()

# Create a new README file
with open(os.path.join(directory, "README.md"), "w") as readme_file:
    # Write the header
    readme_file.write("# List of Folders\n\n")
    
    # Write the list of directories
    for d in directories:
        readme_file.write(f"- {d}\n")