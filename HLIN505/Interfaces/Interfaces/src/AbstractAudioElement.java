
public  abstract class AbstractAudioElement implements ElementAudio{
	private int duration;
	private String title;
	private String fileLocation;
	private java.io.File file;
	public int getDuration() {
		return duration;
	}
	public void setDuration(int duration) {
		this.duration = duration;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getLocation() {
		return fileLocation;
	}
	public void setLocation(String location) {
		this.fileLocation = location;
	}
	
	public AbstractAudioElement(String title, String fileLocation){
		
	}
}
