FROM python:3

COPY movies_by_genre.csv ./movies_by_genre.csv
COPY analysis.py ./analysis.py

RUN pip install numpy pandas

CMD ["python", "./analysis.py"]