import os

def linesCount(directory: str):
    count = 0
    for root, subdirs, files in os.walk(directory):
        for filename in files:
            file_path = os.path.join(root, filename)
            count += sum(1 for line in open(file_path))
    return count

def filesCount(directory: str):
    count = 0
    for root, subdirs, files in os.walk(directory):
        count += len(files)
    return count

root = os.path.abspath(os.path.join(os.getcwd(), '../'))
testing = root + "/tests"
library = root + "/CGM"
samples = root + "/examples"

library_files_count = filesCount(library)
testing_files_count = filesCount(testing)
samples_files_count = filesCount(samples)
total_files_count = testing_files_count + library_files_count + samples_files_count

library_lines_count = linesCount(library)
testing_lines_count = linesCount(testing)
samples_lines_count = linesCount(samples)
total_lines_count = testing_lines_count + library_lines_count + samples_lines_count

print("################")
print("FILES")
print("################")
print("Library:  ", library_files_count)
print("Testing:  ", testing_files_count)
print("Samples:  ", samples_files_count)
print("----------------")
print("Total:    ", total_files_count)
print("################")
print("LINES")
print("################")
print("Library:  ", library_lines_count)
print("Testing:  ", testing_lines_count)
print("Samples:  ", samples_lines_count)
print("----------------")
print("Total:    ", total_lines_count)